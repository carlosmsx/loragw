/*
 * Autor: Carlos Escobar
 * mapeo de la rpi al módulo M95
 * rpi(pin 37)--M95(pin 11)  GPIO26
 * rpi(pin 35)--M95(pin 10)  GPIO19
 */

#include "GPIOClass.h"
#include <unistd.h>

void m95powerUp()
{
	//
	GPIOClass state("6");
	state.export_gpio();
	state.setdir_gpio("in");

	//emerg off
	GPIOClass gpio26("19");
	gpio26.export_gpio();
	gpio26.setdir_gpio("out");
	gpio26.setval_gpio("0");

	//power key
	GPIOClass power_key("26");
	power_key.export_gpio();
	power_key.setdir_gpio("out");
	power_key.setval_gpio("0");

	string str;
	state.getval_gpio(str);
	if (str.at(0) == '0')
	{
		//printf("0->pulso\r\n");
		//pulso de encendido
		power_key.setval_gpio("1");
		sleep(1);
		power_key.setval_gpio("0");
	}
}

void m95powerDown()
{
	//state
	GPIOClass state("6");
	state.export_gpio();
	state.setdir_gpio("in");

	//emerg off
	GPIOClass gpio26("19");
	gpio26.export_gpio();
	gpio26.setdir_gpio("out");
	gpio26.setval_gpio("0");

	//power key
	GPIOClass power_key("26");
	power_key.export_gpio();
	power_key.setdir_gpio("out");
	power_key.setval_gpio("0");

	string str;
	state.getval_gpio(str);
	if (str.at(0) == '1')
	{
		//printf("0->pulso\r\n");
		//pulso de apagado
		power_key.setval_gpio("1");
		sleep(1);
		power_key.setval_gpio("0");
	}
}