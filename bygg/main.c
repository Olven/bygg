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


volatile char *peikar = (char) 0x1200;


int main(void)
{
	uart_init();
	//char string1[90] = "Test String";
	//char string1[100];
	
	// MCU Control Register, SRE(bit 7) to 1 enables External Memory Interface p.30 datasheet
	MCUCR |= (1 << SRE);
	
	// Special Function IO, XMM2 to 1 removes pin 7-4 from the External Memory
	// pin 7-4 are used by the Atmel ICE for programming.
	SFIOR |= (1 << XMM2);
	

	// Test line for testing the latch.
	//volatile char *ext_ram = (char *) 0x1801; // Start address for the SRAM
	//SRAM_test();
	
	
	oled_init();

while(1);
	while(1)
	{

		oled_clear();
	
		uint8_t i = 0;
		
		
		/*
		for (i = 0; i < 8; i = i + 1)
		{
			oled_goto_page(i);
			oled_data_dump();
		}
		*/
		
	}

}