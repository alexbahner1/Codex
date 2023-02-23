
#include "SHT31.h"

SHT31::SHT31(int address)
{
    _address = address;
}

SHT31::SHT31()
{
    _address = SHT31_DEFAULT_ADDR;
}

int SHT31::getTemperature()
{
    Wire.beginTransmission(_address);
    Wire.write(MEASURE_MSB); // Measure Temp and humdi 
    Wire.write(MEASURE_LSB); 
    delay(100);
    Wire.requestFrom(_address,6,true);
    uint16_t temp = (Wire.read() << 8 | Wire.read());// & 0b0000111111111111;
    int8_t data = Wire.read();
    uint16_t humdi = (Wire.read() | Wire.read() << 8) & 0b0000111111111111;
    int8_t data2 = Wire.read();
    Wire.endTransmission();
    uint16_t T = -49 + 315*(temp/(pow(2,16)-1));
    return T;
}

int SHT31::getHumidity()
{
    Wire.beginTransmission(_address);
    Wire.write(MEASURE_MSB); // Measure Temp and humdi 
    Wire.write(MEASURE_LSB); 
    delay(100);
    Wire.requestFrom(_address,6,true);
    uint16_t temp = (Wire.read() << 8 | Wire.read());// & 0b0000111111111111;
    int8_t data = Wire.read();
    uint16_t humdi = (Wire.read() << 8 | Wire.read());
    int8_t data2 = Wire.read();
    Wire.endTransmission();
    uint16_t H = 100 * (humdi/(pow(2,16)-1));
    return H;
}

void SHT31::heaterOn()
{
    Wire.beginTransmission(_address);
    Wire.write(HEATER_MSB);
    Wire.write(HEATER_ENABLE);  
    // delay(100);
    // Wire.endTransmission();
}

void SHT31::heaterOff()
{
    Wire.beginTransmission(_address);
    Wire.write(HEATER_MSB);
    Wire.write(HEATER_DISABLE);  
    // Wire.endTransmission();
}