#include <RadioLib.h>
#include <TinyGPS++.h>      // Mikal Hart v1.0.3
#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Heltec V3 Internal Pins
#define VEXT_PIN  36
#define OLED_RST  21
#define LORA_NSS  8
#define LORA_DIO1 14
#define LORA_NRST 12
#define LORA_BUSY 13

// SD Card Pins - Using separate HSPI bus
#define SD_CS   7
#define SD_SCK  4
#define SD_MISO 5
#define SD_MOSI 6

SPIClass hspi(HSPI); 
SX1262 lora = new Module(LORA_NSS, LORA_DIO1, LORA_NRST, LORA_BUSY);
TinyGPSPlus gps;
HardwareSerial SerialGPS(2); 
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST);

volatile bool txBusy = false;
unsigned long lastActionTime = 0;
bool sdEnabled = false;

// Interrupt for non-blocking LoRa transmission
void onTxDone(void) {
  txBusy = false;
}

// Function to handle SD Mounting and Recovery
void trySDInit() {
  if (SD.begin(SD_CS, hspi, 4000000)) {
    sdEnabled = true;
    File file = SD.open("/flight.csv", FILE_APPEND);
    if(file) {
      file.println("--- LOG SESSION START ---");
      file.println("DATE,TIME,LAT,LON,ALT_FT,SATS");
      file.close();
    }
  } else {
    sdEnabled = false;
  }
}

void setup() {
  Serial.begin(115200);

  // 1. Hardware Power/Reset
  pinMode(VEXT_PIN, OUTPUT);
  digitalWrite(VEXT_PIN, LOW); 
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW); delay(50); digitalWrite(OLED_RST, HIGH);

  // 2. Initialize OLED
  Wire.begin(17, 18);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("BALLOON SYSTEM BOOT");
  display.display();

  // 3. Initialize SD (HSPI Bus)
  hspi.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);
  trySDInit();
  display.println(sdEnabled ? "SD: READY" : "SD: NOT FOUND");
  display.display();

  // 4. Initialize GPS
  SerialGPS.begin(9600, SERIAL_8N1, 45, 46);
  // UBX Airborne < 1g Mode Command
  byte packet[] = {0xB5, 0x62, 0x06, 0x24, 0x24, 0x00, 0xFF, 0xFF, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00, 0x05, 0x00, 0xFA, 0x00, 0xFA, 0x00, 0x64, 0x00, 0x2C, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0xDC};
  SerialGPS.write(packet, sizeof(packet));
  display.println("GPS: AIRBORNE SET");
  display.display();

  // 5. Initialize LoRa
  // freq: 915.0, bw: 125.0, sf: 7, cr: 5, sync: 0x12, pwr: 10, preamble: 8, tcxo: 1.6V, LDO: false (DC-DC)
  int status = lora.begin(915.0, 125.0, 7, 5, 0x12, 10, 8, 1.6, false); 
  if (status == RADIOLIB_ERR_NONE) {
    display.print("LORA PING... ");
    display.display();
    
    // Blocking startup ping
    int txStatus = lora.transmit("BALLOON_ONLINE_STARTUP");
    
    if(txStatus == RADIOLIB_ERR_NONE) display.println("SENT");
    else display.println("FAIL");
    
    lora.setPacketSentAction(onTxDone);
  } else {
    display.printf("LORA ERR: %d\n", status);
  }
  display.display();
  delay(2000);
}

void loop() {
  // Constant GPS Feeding
  while (SerialGPS.available() > 0) {
    gps.encode(SerialGPS.read());
  }

  // Action Cycle: 10 Seconds
  if (millis() - lastActionTime > 10000) {
    
    // A. SD Recovery Check
    if (!sdEnabled) {
      trySDInit();
    }

    // B. Build Data String
    char dataBuf[128];
    snprintf(dataBuf, sizeof(dataBuf), "%02d/%02d/%d,%02d:%02d:%02d,%.6f,%.6f,%.1f,%d",
             gps.date.month(), gps.date.day(), gps.date.year(),
             gps.time.hour(), gps.time.minute(), gps.time.second(),
             gps.location.lat(), gps.location.lng(), gps.altitude.feet(), gps.satellites.value());

    // C. Write to SD
    if (sdEnabled) {
      File dataFile = SD.open("/flight.csv", FILE_APPEND);
      if (dataFile) {
        dataFile.println(dataBuf);
        dataFile.close();
      } else {
        sdEnabled = false; // Trigger recovery on next loop
      }
    }

    // D. Transmit LoRa
    if (!txBusy) {
      txBusy = true;
      lora.startTransmit(dataBuf);
    }
    
    lastActionTime = millis();
  }

  updateDisplay();
}

void updateDisplay() {
  display.clearDisplay();
  display.setCursor(0, 0);

  // Date and Time (Always attempt to show)
  if (gps.date.isValid() && gps.time.isValid()) {
    display.printf("%02d/%02d/%02d  %02d:%02d:%02d\n", 
                   gps.date.month(), gps.date.day(), gps.date.year() % 100,
                   gps.time.hour(), gps.time.minute(), gps.time.second());
  } else {
    display.printf("SATS: %d  Wait Time...\n", gps.satellites.value());
  }

  display.println("--------------------");

  // GPS Position Data
  if (gps.location.isValid()) {
    display.printf("ALT: %.0f ft\n", gps.altitude.feet());
    display.printf("LAT: %.5f\n", gps.location.lat());
    display.printf("LON: %.5f\n", gps.location.lng());
  } else {
    display.println("GPS: SEARCHING...");
    display.printf("Visible Satellites: %d\n", gps.satellites.value());
    if (gps.satellites.value() > 2) display.println("Wait for lock...");
  }

  // SD Status Bar
  display.setCursor(0, 56);
  if (!sdEnabled) {
    display.setTextColor(BLACK, WHITE);
    display.print(" SD: ERROR (RETRYING) ");
    display.setTextColor(WHITE, BLACK);
  } else {
    display.print("SD: LOGGING OK");
  }

  display.display();
}
