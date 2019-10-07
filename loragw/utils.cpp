/*
 * Autor: Carlos Escobar
 */

#include "GPIOClass.h"
#include <unistd.h>

void ledPowerOn()
{
	GPIOClass led("13");
	led.export_gpio();
	led.setdir_gpio("out");
	led.setval_gpio("1");
}

void ledPowerOff()
{
	GPIOClass led("13");
	led.export_gpio();
	led.setdir_gpio("out");
	led.setval_gpio("0");
}