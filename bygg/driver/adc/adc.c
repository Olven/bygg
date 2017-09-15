/*
 * adc.c
 *
 * Created: 15.09.2017 11:48:59
 *  Author: sondstaf
 */ 

#include <avr/io.h>
#include "adc.h"




volatile char * adc=(char *) 0x1400;



uint8_t ADC_read(channel input)
{
	DDRE |= (0 << DDE0);	// Sånn at vi får rett DDR, som si vill ha til input.
	
	*adc = input;
	while(PINE & (1 << INT2)) // https://electronics.stackexchange.com/questions/5302/how-do-i-read-digital-input-on-atmega16
	{
		
	}
		
	return *adc;
	
}