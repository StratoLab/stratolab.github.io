#include <Arduino.h>
#include <Wire.h>
#include <BMP180.h>
#include "FS.h"
#include "SD.h"
#include "SPI.h"

// create a sensor object (085 is not a typo) and set I2C pins for communication
BMP085 bmp;               
#define SDA 46           
#define SCL 45

// Define SPI and set pins for communication
SPIClass spi;
#define CS    4
#define MOSI  5
#define CLK   6
#define MISO  7

void setup() {
  Serial.begin(115200);
  mountSDCard();
 	Wire.begin(SDA, SCL);   // set up the I2C protocol to communicate with sensors
  bmp.begin();            // start communicating with the BMP180 sensor
  delay(1000);
}

void loop() {
  double tempC = bmp.readTemperature();
  char data[10];                        // create a character array to hold output
  dtostrf(tempC, 0, 2, data);           // convert the temp int characters
  appendDataToFile("/test.txt",data);    // write the data characters to file 
  delay(3000);
}

void mountSDCard(){
  Serial.println("Mounting SD Card....");
  spi.begin(CLK, MISO, MOSI, CS);                     // init SPI with correct pins
  if(!SD.begin(CS, spi)){                             // try to communicate with SD card
    Serial.println("Card mount failed");
    return;
  }
  int cardSize = SD.cardSize() / (1024 * 1024 * 1024);// find card size in gigbytes
  Serial.print("Mounted SD card with size of ");
  Serial.print(cardSize);
  Serial.println(" Gb");
}

void appendDataToFile(const char * filename, const char * data){
    File file = SD.open(filename, FILE_APPEND);       // try to open the file to append (add on) data
    if(!file){                                        // check file access error
        Serial.println("Failed to open file");
    }
    if(file.println(data)){                             // try to actually write the data
        Serial.printf("Data written to %s: %s\n",filename, data);
    } else {                                          // check file writing error
        Serial.println("File write failed");
    }
    file.close();                                     // close file to finish up
}