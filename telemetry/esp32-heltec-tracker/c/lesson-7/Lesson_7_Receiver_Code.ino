#include "HT_st7735.h"
#include <RadioLib.h>

#define LORA_NSS  8
#define LORA_DIO1 14
#define LORA_NRST 12
#define LORA_BUSY 13
#define VEXT_CTRL 3 

HT_st7735 screen;
SX1262 lora = new Module(LORA_NSS, LORA_DIO1, LORA_NRST, LORA_BUSY);

volatile bool packetAvailable = false;

void onReceive(void) {
  packetAvailable = true;
}

void setup() {
  Serial.begin(115200);

  pinMode(VEXT_CTRL, OUTPUT);
  digitalWrite(VEXT_CTRL, LOW); 
  delay(100);

  screen.st7735_init();
  screen.st7735_fill_screen(ST7735_BLACK);
  screen.st7735_write_str(0, 0, "RECEIVER READY", Font_7x10, ST7735_YELLOW, ST7735_BLACK);
  
  // Frequency: 915.0 MHz, TCXO: 1.6V, Regulator: DC-DC
  int status = lora.begin(915.0, 125.0, 7, 5, 0x12, 10, 8, 1.6, false); 

  if (status == RADIOLIB_ERR_NONE) {
    screen.st7735_write_str(0, 15, "LORA: OK", Font_7x10, ST7735_GREEN, ST7735_BLACK);
    lora.setPacketReceivedAction(onReceive);
    lora.startReceive(); 
  }
}

void loop() { 
  if(packetAvailable){
    readPacket();
  } 
}

void readPacket() {
    String data;
    int status = lora.readData(data);
    
    if (status == RADIOLIB_ERR_NONE) {
        screen.st7735_fill_screen(ST7735_BLACK);
        
        // --- ROW 1: HEADER ---
        screen.st7735_write_str(0, 0, "PAYLOAD:", Font_7x10, ST7735_YELLOW, ST7735_BLACK);
        
        // --- ROW 2: DATA (Starts at 12, allows wrapping to ~34) ---
        screen.st7735_write_str(0, 12, data, Font_7x10, ST7735_WHITE, ST7735_BLACK);

        // --- ROW 3: RADIO STATS ---
        // Lowered to Y=40 to clear potential 2nd line of payload text
        char radioStr[40];
        sprintf(radioStr, "RSSI:%-4.0f SNR:%-3.1f", lora.getRSSI(), lora.getSNR());
        screen.st7735_write_str(0, 40, radioStr, Font_7x10, ST7735_CYAN, ST7735_BLACK);

        // --- ROW 4: FREQUENCY ERROR ---
        char feStr[40];
        sprintf(feStr, "FE: %-5.0f Hz", lora.getFrequencyError());
        screen.st7735_write_str(0, 53, feStr, Font_7x10, ST7735_WHITE, ST7735_BLACK);

    } else {
        // ERROR HANDLING (Screen turns red text on failure)
        screen.st7735_fill_screen(ST7735_BLACK);
        screen.st7735_write_str(0, 0, "RX ERROR!", Font_7x10, ST7735_RED, ST7735_BLACK);
        if(status == RADIOLIB_ERR_CRC_MISMATCH) {
            screen.st7735_write_str(0, 15, "CRC CORRUPTION", Font_7x10, ST7735_RED, ST7735_BLACK);
        } else {
            screen.st7735_write_str(0, 15, "CODE: " + String(status), Font_7x10, ST7735_WHITE, ST7735_BLACK);
        }
    }

    packetAvailable = false;
    lora.startReceive(); 
}
