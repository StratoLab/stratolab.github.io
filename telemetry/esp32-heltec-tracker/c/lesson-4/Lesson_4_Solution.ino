#include <Arduino.h>
#include <Wire.h>
#include <BMP180.h>
#include "HT_st7735.h"

HT_st7735 screen;

BMP085 bmp;               // create a sensor object (085 is not a typo)
#define SDA 46            // ...and set its I2C pin connections
#define SCL 45

void setup() {
	Wire.begin(SDA, SCL);   // set up the I2C protocol to communicate with sensors
  Serial.begin(115200);   // set up the serial protocol to  communicate with laptop
  bmp.begin();            // start communicating with the BMP180 sensor
  screen.st7735_init();   // start SPI communication with the LED screen
  delay(1000);            // pause to allow all initialization to finish
  scan();                 // find all connected I2C devices
}

void scan(){
	Serial.println("Scanning all I2C addresses...");
	for(int address = 1; address < 127; address++ ){
		// try to communicate to this address
    Wire.beginTransmission(address);
		byte error = Wire.endTransmission();
    // a reply of 0 indicates a successful connection
		if (error == 0)	{
			Serial.print("I2C device found at address 0x");
			Serial.println(address,HEX);
		}
	}
	Serial.println("done");
}

void loop(){
  double tempC =bmp.readTemperature();
  Serial.print("Temperature = ");
  Serial.print(tempC);
  Serial.println(" *C");

  int press =  bmp.readPressure();
  Serial.print("Pressure = ");
  Serial.print(press);
  Serial.println(" Pa");

  Serial.println();

  screen.st7735_fill_screen(ST7735_BLACK);
  screen.st7735_write_str(20, 20, "BMP180 Data", Font_11x18, ST7735_BLACK, ST7735_WHITE);
  String tempInfo = (String)tempC + " degC";
	screen.st7735_write_str(40, 40, tempInfo, Font_7x10, ST7735_RED, ST7735_BLACK);
  String pressInfo = (String)press + " Pa";
	screen.st7735_write_str(40, 50, pressInfo, Font_7x10, ST7735_GREEN, ST7735_BLACK);

  for(int x = 0; x < 320; x++){
     screen.st7735_draw_pixel(x, 0, ST7735_BLUE);
     screen.st7735_draw_pixel(x, 79, ST7735_BLUE);
  }
  
  delay(3000);
}


