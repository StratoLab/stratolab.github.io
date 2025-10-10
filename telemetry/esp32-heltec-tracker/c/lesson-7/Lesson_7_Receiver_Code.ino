#include "HT_st7735.h"
#include <RadioLib.h>

#define LORA_NSS  8
#define LORA_DIO1 14
#define LORA_NRST 12
#define LORA_BUSY 13

HT_st7735 screen;

// initalize lora radio and make an interrupt function for when packets arrive
SX1262 lora = new Module(LORA_NSS, LORA_DIO1, LORA_NRST, LORA_BUSY);
volatile bool packetAvailable = false;
ICACHE_RAM_ATTR             // puts onReceive in RAM for better memory access
void onReceive(void) {
  packetAvailable = true;
}

void setup() {
  Serial.begin(115000);
  screen.st7735_init();
  screen.st7735_fill_screen(ST7735_BLACK);
  loraInit();
}

void loop() { 
  if(packetAvailable){
    readPacket();
  } 
}
  
int loraInit(){
  screen.st7735_write_str(0, 0, "LORA init...", Font_7x10, ST7735_WHITE, ST7735_BLACK);
  int status1 = lora.begin();                    
  lora.setPacketReceivedAction(onReceive);      // tells lora to call the interrupt function when a packet arrives
  int status2 = lora.startReceive();

  if (status1 == RADIOLIB_ERR_NONE && status2 == RADIOLIB_ERR_NONE) {
    screen.st7735_write_str(90, 0, "OK", Font_7x10, ST7735_GREEN, ST7735_BLACK);
  } else {
    screen.st7735_write_str(90, 0, "ERR", Font_7x10, ST7735_RED, ST7735_BLACK);
    screen.st7735_write_str(120, 0,  (String)status1, Font_7x10, ST7735_WHITE, ST7735_BLACK);
    screen.st7735_write_str(140, 0,  (String)status2, Font_7x10, ST7735_WHITE, ST7735_BLACK);
  }
  return status1 + status2;                       // can be used for status checking: will be 0 if no errors
}

void readPacket() {
    String data;
    int status = lora.readData(data);             // data is stored into "data" and status is stored is "status"
    if (status == RADIOLIB_ERR_NONE) {
        screen.st7735_write_str(0, 12, "Data: ", Font_7x10, ST7735_WHITE, ST7735_BLACK);
        screen.st7735_write_str(64, 12, data, Font_7x10, ST7735_WHITE, ST7735_BLACK);

        String rssi = (String)lora.getRSSI();
        screen.st7735_write_str(0, 24, "RSSI:          dBm", Font_7x10, ST7735_WHITE, ST7735_BLACK);
        screen.st7735_write_str(64, 24, rssi, Font_7x10, ST7735_WHITE, ST7735_BLACK);

        String snr = (String)lora.getSNR();
        screen.st7735_write_str(0, 36, "SNR:           dB", Font_7x10, ST7735_WHITE, ST7735_BLACK);
        screen.st7735_write_str(64, 36, snr, Font_7x10, ST7735_WHITE, ST7735_BLACK);

        String freqErr = (String)lora.getFrequencyError();
        screen.st7735_write_str(0, 48, "Freq Err:       Hz", Font_7x10, ST7735_WHITE, ST7735_BLACK);
        screen.st7735_write_str(64, 48, freqErr, Font_7x10, ST7735_WHITE, ST7735_BLACK);

    } else if (status == RADIOLIB_ERR_CRC_MISMATCH) {
        screen.st7735_write_str(0, 12, "CRC Error", Font_7x10, ST7735_RED, ST7735_BLACK);
        screen.st7735_write_str(0, 24, "Malformed Packet", Font_7x10, ST7735_WHITE, ST7735_BLACK);
    } else {
        String err = (String)status;
        screen.st7735_write_str(0, 12, "Rx Error:", Font_7x10, ST7735_RED, ST7735_BLACK);
        screen.st7735_write_str(80, 12, err, Font_7x10, ST7735_WHITE, ST7735_BLACK);
    }
    packetAvailable = false;   // reset flag
}

