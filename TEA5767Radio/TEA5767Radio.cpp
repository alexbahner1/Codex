#include <Arduino.h>
#include <TEA5767Radio.h>

TEA5767Radio::TEA5767Radio(int address)
{
    _address = address;
}

TEA5767Radio::TEA5767Radio()
{
    _address = 0x60;
}

void TEA5767Radio::setFrequency(float frequency)
{
    unsigned int freqB = 4 * (frequency * 1000000 + 225000) / 32768;
    byte freqH = freqB >> 8;
    byte freqL = freqB & 0xff; 

    Wire.beginTransmission(_address);
    Wire.write(freqH);
    Wire.write(freqL); 
    Wire.write(0xb0); 
    Wire.write(0x10); 
    Wire.write(0x00);
    Wire.endTransmission();
    delay(100);
}