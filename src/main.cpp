#include "mini_mini_HAL.h"
#include <util/delay.h> // Для функции _delay_ms

#define LED 13

Mini_mini_HAL HAL;

void setup()
{
  HAL.PinMode(LED, OUTPUT); // Настройка пина LED как выход
}

void loop()
{
  HAL.DigitalWrite(LED, HIGH); // Включить LED
  _delay_ms(1000);              // Задержка 500 мс
  HAL.DigitalWrite(LED, LOW);  // Выключить LED
  _delay_ms(500);              // Задержка 500 мс
}

int main()
{
  setup();
  while (true)
  {
    loop();
  }
}
