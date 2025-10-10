#include "Arduino.h"
#include "HT_TinyGPS++.h"
#define GPS_ON 3
#define GPS_TX 33
#define GPS_RX 34
#define GPS_BAUD 115200

TinyGPSPlus gps;

void setup(){
  pinMode(GPS_ON,OUTPUT);
	digitalWrite(GPS_ON,HIGH);
	Serial1.begin(GPS_BAUD,SERIAL_8N1,GPS_TX,GPS_RX);    
  delay(1000);

  Serial.begin(115200);  
  Serial.println("GPS_test");
}


void loop(){
  while(Serial1.available()){
    int c = Serial1.read();
    Serial.print((char)c);
    gps.encode(c);
  }
  Serial.println();
  Serial.printf("GPS status\n");
  Serial.printf("Time: %02d:%02d:%02d\n",gps.time.hour(),gps.time.minute(),gps.time.second());
  Serial.printf("Tracking %d satellites\n",gps.satellites.value());
  Serial.printf("Latitude %f deg\n",gps.location.lat());
  Serial.printf("Longtitude %f deg\n",gps.location.lng());
  Serial.printf("Altitude %f ft\n",gps.altitude.feet());
  Serial.printf("Heading %f deg\n",gps.course.deg());
  Serial.printf("Speed %f m/s\n",gps.speed.mps());
  Serial.printf("Accuracy %f m\n",gps.hdop.hdop());
  Serial.println();
  
  delay(1000);
}
