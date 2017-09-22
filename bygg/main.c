/*
 * bygg.c
 *
 * Created: 08.09.2017 09:19:47
 *  Author: sondstaf
 */ 

#define F_CPU 4915200UL

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "driver/uart/uart.h"
#include "testExternalMemory.h"
#include "driver/adc/adc.h"
#include "driver/joystick/joystick.h"


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
	SRAM_test();
	
	
	//volatile char * test=(char *) 1400;
	//volatile char * invTest=(char *) 1800;
	
	joystick_init();
	
	while(1)
	{
		printf("Inside while loop...\n");
		
		volatile uint8_t result = ADC_read(joystick_x);
		//const char *char_pointer_x = (char*)result;
		printf("Result x: %i \n",result);
		
		
		result = ADC_read(joystick_y);
		printf("Result y: %i \n",result);
		


	}

}