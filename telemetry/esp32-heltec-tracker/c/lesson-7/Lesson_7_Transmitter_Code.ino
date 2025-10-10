#include "HT_st7735.h"
#include <RadioLib.h>

#define LORA_NSS  8
#define LORA_DIO1 14
#define LORA_NRST 12
#define LORA_BUSY 13

HT_st7735 screen;

// initalize lora radio and make an interrupt function for when packets finish sending
SX1262 lora = new Module(LORA_NSS, LORA_DIO1, LORA_NRST, LORA_BUSY);
volatile bool txBusy = false;
ICACHE_RAM_ATTR             // puts onReceive in RAM for better memory access
void onTxDone(void) {
  txBusy = false;
}
int transmissionStatus = RADIOLIB_ERR_NONE;   // initial status is no errors
int packetCount = 0;

void setup() {
  Serial.begin(115000);
  screen.st7735_init();
  screen.st7735_fill_screen(ST7735_BLACK);
  loraInit();
}

void loop() {
  if(!txBusy){
    sendPacket();
  }
  delay(1000);
}

int loraInit(){
  screen.st7735_write_str(0, 0, "LORA init...", Font_7x10, ST7735_WHITE, ST7735_BLACK);

  int status = lora.begin();
  if (status == RADIOLIB_ERR_NONE) {
    screen.st7735_write_str(90, 0, "OK", Font_7x10, ST7735_GREEN, ST7735_BLACK);
  } else {
    screen.st7735_write_str(90, 0, "ERR", Font_7x10, ST7735_RED, ST7735_BLACK);
    screen.st7735_write_str(100, 0,  (String)status, Font_7x10, ST7735_RED, ST7735_BLACK);
  }
  lora.setPacketSentAction(onTxDone);
  delay(2000);
  return status;
}

void sendPacket(){
  txBusy = true;
  String str = "Packet# " + String(packetCount);
  packetCount++;
  screen.st7735_write_str(0, 10, "Sending: ", Font_7x10, ST7735_WHITE, ST7735_BLACK);
  screen.st7735_write_str(56, 10, str, Font_7x10, ST7735_WHITE, ST7735_BLACK);
  transmissionStatus = lora.startTransmit(str);
  delay(1000);
  lora.finishTransmit();

  if (transmissionStatus == RADIOLIB_ERR_NONE) {
    String msg = "OK";
    screen.st7735_write_str(140, 10, msg, Font_7x10, ST7735_GREEN, ST7735_BLACK);      
  } else {
    String msg = "ERR "+transmissionStatus;
    screen.st7735_write_str(140, 10, msg, Font_7x10, ST7735_RED, ST7735_BLACK);      
  }
}
