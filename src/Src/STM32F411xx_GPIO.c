/*
 * STM32F411xx_GPIO.c
 *
 * Created on: 03-Nov-2021
 * Author: Devashish Lahariya
*/

#include "STM32F411xx_GPIO.h"

void GPIO_setMode(GPIO_PERIPHERALS_t* _port, uint8_t _pin, uint8_t _speed, uint8_t _type, uint8_t _mode)
{
	_port -> MODER   &= ~(3 << (_pin * 2));
	_port -> OSPEEDR &= ~(3 << (_pin * 2));
	_port -> OTYPER  &= ~(1 << _pin);

	if(_mode > GPIO_MODE_INPUT)
	{
		_port -> MODER |= (_mode << (_pin * 2));
	}

	if(_speed > GPIO_LOW_SPEED)
	{
		_port -> OSPEEDR |= (_speed << (_pin * 2));
	}

	if(_type > GPIO_MODE_PUSH_PULL)
	{
		_port -> OTYPER  |= (_type << _pin);
	}
}

void GPIO_pin(GPIO_PERIPHERALS_t* _port, uint8_t _pin, uint8_t _state)
{
	if(_state == 0)
	{
		_port -> ODR &= ~(1 << _pin);
	}
	else
	{
		_port -> ODR |= (1 << _pin);
	}
}

void GPIO_toggle(GPIO_PERIPHERALS_t* _port, uint8_t _pin)
{
	_port -> ODR ^= (1 << _pin);
}
