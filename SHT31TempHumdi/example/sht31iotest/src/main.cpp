#include <Arduino.h>
#include "SHT31.h"

SHT31 sen = SHT31();
int = temp;

void setup(){
  Serial.begin(9600);
  Wire.begin(); 
}

void loop(){
  temp = sen.getTemperature();
  Serial.println(temp);
}