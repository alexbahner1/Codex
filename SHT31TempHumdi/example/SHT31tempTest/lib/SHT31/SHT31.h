#ifndef SHT31_h
#define SHT31_h

#include <Wire.h>
#include <Arduino.h>
#include <math.h>

#define SHT31_DEFAULT_ADDR 0x44 
#define MEASURE_MSB 0x24 
#define MEASURE_LSB 0x00
#define HEATER_MSB 0x30 
#define HEATER_ENABLE 0x6d
#define HEATER_DISABLE 0x66

class SHT31
{
    private:
        int _address;
    public:
        SHT31();
        SHT31(int address);
        int getTemperature();
        int getHumidity();
        void heaterOn();
        void heaterOff(); 
};

#endif