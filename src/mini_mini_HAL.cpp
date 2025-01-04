#include "mini_mini_HAL.h"
#include <avr/io.h> // Для работы с регистрами AVR

// Преобразование номера пина в порт и бит
struct PinMap
{
	volatile uint8_t *ddr;	// Регистр направления (DDR)
	volatile uint8_t *port; // Регистр данных (PORT)
	uint8_t bit;			// Бит в регистре
};

// Карта пинов для Arduino Uno
PinMap getPinMap(uint8_t pin)
{
	if (pin >= 0 && pin <= 7)
	{ // Порт D (пины 0-7)
		return {&DDRD, &PORTD, pin};
	}
	else if (pin >= 8 && pin <= 13)
	{ // Порт B (пины 8-13)
		return {&DDRB, &PORTB, pin - 8};
	}
	else if (pin >= 14 && pin <= 19)
	{ // Аналоговые пины A0-A5 (порт C)
		return {&DDRC, &PORTC, pin - 14};
	}
	return {nullptr, nullptr, 0}; // Неверный пин
}

// Установка режима пина
void Mini_mini_HAL::PinMode(uint8_t pin, uint8_t mode)
{
	PinMap map = getPinMap(pin);
	if (map.ddr)
	{
		if (mode == OUTPUT)
		{
			*(map.ddr) |= (1 << map.bit); // Установить бит в DDR (выход)
		}
		else
		{
			*(map.ddr) &= ~(1 << map.bit); // Сбросить бит в DDR (вход)
		}
	}
}

// Установка значения на пине
void Mini_mini_HAL::DigitalWrite(uint8_t pin, uint8_t value)
{
	PinMap map = getPinMap(pin);
	if (map.port)
	{
		if (value == HIGH)
		{
			*(map.port) |= (1 << map.bit); // Установить высокий уровень
		}
		else
		{
			*(map.port) &= ~(1 << map.bit); // Установить низкий уровень
		}
	}
}
