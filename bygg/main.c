/*
 * bygg.c
 *
 * Created: 08.09.2017 09:19:47
 *  Author: sondstaf
 */ 

#define F_CPU 4915200UL

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>

// Vår eigne hedarar.
#include "driver/uart/uart.h"
#include "testExternalMemory.h"
#include "driver/adc/adc.h"
#include "driver/joystick/joystick.h"
#include "driver/oled/oled.h"

#include "menu/menu.h"



int main(void)
{
	
	uart_init();

	
	// MCU Control Register, SRE(bit 7) to 1 enables External Memory Interface p.30 datasheet
	MCUCR |= (1 << SRE);
	
	// Special Function IO, XMM2 to 1 removes pin 7-4 from the External Memory
	// pin 7-4 are used by the Atmel ICE for programming.
	SFIOR |= (1 << XMM2);
	/*
	oled_init();
	oled_clear();
	create_menu();
	draw_cursor();
	*/
	while(1)
	{
		

		/*
		if(strcmp(direction, "Up") != 0)
		{
			set_cursor_position(-1);
		}
		if(strcmp(direction, "Down") != 0)
		{
			set_cursor_position(1);
		}
		*/
		
	}

}