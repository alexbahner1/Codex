#ifndef SHT31_h
#define SHT31_h

#include <Wire.h>

#define SHT31_DEFAULT_ADDR 0x44 
#define MEASURE_MSB = 0x24 
#define MEASURE_LSB = 0x00

class SHT31
{
    private:
        int _address
    public:
        SHT31();
        SHT31(int address);
        int getTemperature();
};

#endif