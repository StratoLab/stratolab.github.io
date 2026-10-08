#include "HT_st7735.h"      
#include "HT_TinyGPS++.h"   
#include <RadioLib.h>

// --- Tracker v1.2 Internal GPS Pins ---
#define GPS_RX_PIN  33      // ESP32 RX <- GPS TX
#define GPS_TX_PIN  34      // ESP32 TX -> GPS RX
#define GPS_RESET   35      // GPS Reset Pin
#define VEXT_CTRL   3       // Power Control (LOW = ON)

// --- LoRa Pins ---
#define LORA_NSS    8
#define LORA_DIO1   14
#define LORA_NRST   12
#define LORA_BUSY   13

// Objects
HT_st7735 screen;
SX1262 lora = new Module(LORA_NSS, LORA_DIO1, LORA_NRST, LORA_BUSY);
TinyGPSPlus gps;
HardwareSerial SerialGPS(1); 

volatile bool txBusy = false;
unsigned long lastActionTime = 0;
bool lastLockStatus = false; 

void onTxDone(void) {
  txBusy = false;
}

void setup() {
  Serial.begin(115200);

  // 1. Power on hardware
  pinMode(VEXT_CTRL, OUTPUT);
  digitalWrite(VEXT_CTRL, LOW);   
  pinMode(GPS_RESET, OUTPUT);
  digitalWrite(GPS_RESET, HIGH);  
  delay(500);

  // 2. Initialize Screen
  screen.st7735_init();
  screen.st7735_fill_screen(ST7735_BLACK);
  screen.st7735_write_str(0, 0, "TRACKER V1.2", Font_7x10, ST7735_YELLOW, ST7735_BLACK);

  // 3. Initialize Internal GPS (RX=33, TX=34 @ 115200)
  SerialGPS.begin(115200, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);

  // 4. Initialize LoRa
  int status = lora.begin(915.0, 125.0, 7, 5, 0x12, 10, 8, 1.6, false);
  if (status == RADIOLIB_ERR_NONE) {
    lora.setPacketSentAction(onTxDone);
    lora.transmit("TRACKER_ONLINE");
  }

  delay(2000);
  screen.st7735_fill_screen(ST7735_BLACK);
}

void loop() {
  while (SerialGPS.available() > 0) {
    gps.encode(SerialGPS.read());
  }

  // Detect transition from "No Lock" to "Lock" to wipe screen once to clear old text
  if (gps.location.isValid() != lastLockStatus) {
    lastLockStatus = gps.location.isValid();
    screen.st7735_fill_screen(ST7735_BLACK); 
  }

  if (millis() - lastActionTime > 10000) {
    if (!txBusy && gps.location.isValid()) {
      transmitData();
    }
    lastActionTime = millis();
  }

  updateScreen();
}

void updateScreen() {
  // --- ROW 1: DATE ---
  if (gps.date.isValid()) {
    char dStr[24];
    sprintf(dStr, "DATE: %02d/%02d/%04d", gps.date.month(), gps.date.day(), gps.date.year());
    screen.st7735_write_str(0, 0, dStr, Font_7x10, ST7735_YELLOW, ST7735_BLACK);
  } else {
    screen.st7735_write_str(0, 0, "DATE: SYNCING... ", Font_7x10, ST7735_WHITE, ST7735_BLACK);
  }

  // --- ROW 2: TIME ---
  if (gps.time.isValid()) {
    char tStr[24];
    sprintf(tStr, "TIME: %02d:%02d:%02d ", gps.time.hour(), gps.time.minute(), gps.time.second());
    screen.st7735_write_str(0, 12, tStr, Font_7x10, ST7735_YELLOW, ST7735_BLACK);
  } else {
    screen.st7735_write_str(0, 12, "TIME: SYNCING... ", Font_7x10, ST7735_WHITE, ST7735_BLACK);
  }

  // --- GPS DATA BLOCK (Shifted Up) ---
  if (gps.location.isValid()) {
    char satStr[24], latStr[24], lonStr[24], altStr[24];
    
    // Using %- pads the string with spaces to overwrite old characters
    sprintf(satStr, "SATS: %-2d      ", gps.satellites.value());
    sprintf(latStr, "LAT: %-10.5f ", gps.location.lat());
    sprintf(lonStr, "LON: %-10.5f ", gps.location.lng());
    sprintf(altStr, "ALT: %-7.0fft", gps.altitude.feet()); // Removed space before 'ft' to save width

    screen.st7735_write_str(0, 28, satStr, Font_7x10, ST7735_GREEN, ST7735_BLACK);
    screen.st7735_write_str(0, 40, latStr, Font_7x10, ST7735_WHITE, ST7735_BLACK);
    screen.st7735_write_str(0, 52, lonStr, Font_7x10, ST7735_WHITE, ST7735_BLACK);
    screen.st7735_write_str(0, 64, altStr, Font_7x10, ST7735_CYAN, ST7735_BLACK);
  } 
  else {
    screen.st7735_write_str(0, 28, "STATUS: NO LOCK ", Font_7x10, ST7735_RED, ST7735_BLACK);
    
    char sCount[24];
    sprintf(sCount, "SATS VISIBLE: %-2d", gps.satellites.value());
    screen.st7735_write_str(0, 40, sCount, Font_7x10, ST7735_WHITE, ST7735_BLACK);
    
    // Clear the unused data lines below searching status
    screen.st7735_write_str(0, 52, "                ", Font_7x10, ST7735_BLACK, ST7735_BLACK);
    screen.st7735_write_str(0, 64, "                ", Font_7x10, ST7735_BLACK, ST7735_BLACK);
  }
}

void transmitData() {
  txBusy = true;
  char payload[120];
  sprintf(payload, "%02d/%02d %02d:%02d,%.5f,%.5f,%.0f,%d",
          gps.date.month(), gps.date.day(),
          gps.time.hour(), gps.time.minute(),
          gps.location.lat(), gps.location.lng(), 
          gps.altitude.feet(), gps.satellites.value());

  lora.startTransmit(payload);
}
