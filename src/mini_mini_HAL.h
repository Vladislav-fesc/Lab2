#ifndef MINI_MINI_HAL_H
#define MINI_MINI_HAL_H

#include <stdint.h>

// Определяем режимы пинов
#define INPUT 0x00
#define OUTPUT 0x01
#define HIGH 0x01
#define LOW 0x00

class Mini_mini_HAL
{
public:
    void PinMode(uint8_t pin, uint8_t mode);
    void DigitalWrite(uint8_t pin, uint8_t value);
};

#endif // MINI_MINI_HAL_H
