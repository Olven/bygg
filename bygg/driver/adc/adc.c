/*
 * adc.c
 *
 * Created: 15.09.2017 11:48:59
 *  Author: sondstaf
 */

#include <avr/io.h>
#include "adc.h"
//#include "driver/uart/uart.h"


#define F_CPU 4915200
#include <avr/delay.h>
volatile uint8_t * adc=(char *) 0x1400;
/*  // Not needed.
void ADC_init()
{
	EMCUCR |= (1 << ISC2);
	GICR |= (1 << INT2);
}
*/

uint8_t ADC_read(channel input)
{
	//DDRE &= ~(1 << DDE0);
	*adc = input;
	//while(PINE & (1 << INT2));
	_delay_ms(50);

	return *adc;

}
