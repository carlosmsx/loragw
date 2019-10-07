#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "m95utils.h"
#include "utils.h"

//cd /sbin
//sudo cp ~/projects/loragw/bin/ARM/Debug/loragw.out loragw

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("parametros:\r\n");
		printf("  -gprs_on		enciende modulo gprs\r\n");
		printf("  -gprs_off		apaga modulo gprs\r\n");
		printf("  -led_on		enciende led test\r\n");
		printf("  -led_off		apaga led test\r\n");
		printf("\r\n");
		exit(0);
	}

	if (argc == 2 && !strcmp(argv[1], "-gprs_on"))
	{
		m95powerUp();
		exit(0);
	}
	else if (argc == 2 && !strcmp(argv[1], "-gprs_off"))
	{
		m95powerDown();
		exit(0);
	}
	else if (argc == 2 && !strcmp(argv[1], "-led_on"))
	{
		ledPowerOn();
		exit(0);
	}
	else if (argc == 2 && !strcmp(argv[1], "-led_off"))
	{
		ledPowerOff();
		exit(0);
	}
	return 0;
}