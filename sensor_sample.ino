#include "ESC2nd.h"

Sensor sensor(DEVICE_ADDR1);

void setup(){
  Serial.begin(9600);
  delay(1000);
}

void loop(){
  int value[8];
  sensor.read(value);

  for(int i=0;i<8;i++){
   Serial.print(value[i]);
   Serial.print(" ");
  }
  Serial.println();
  delay(100);
}
