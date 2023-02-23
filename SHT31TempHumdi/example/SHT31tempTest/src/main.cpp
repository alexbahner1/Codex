#include <Arduino.h>
#include "SHT31.h"

SHT31 sen = SHT31();
int temp = 0;
int humi = 0;
int counter = 0; 

void setup(){
  Serial.begin(9600);
  Wire.begin(); 

  // sen.heaterOff();
}

void loop(){
  temp = sen.getTemperature();
  sen.heaterOn();
  humi = sen.getHumidity();
  

  Serial.print("T:");
  Serial.print(temp);
  Serial.print(" H:");
  Serial.println(humi);
  delay(1000);

  //heater code 
  // counter = counter + 1;
  // if(counter == 10){
  //   sen.heaterOn();
  //   Serial.println("heater on");
  // }
  // if(counter >= 30){
  //   sen.heaterOff();
  //   Serial.println("heater off");
  //   counter = 0; 
  // }
}