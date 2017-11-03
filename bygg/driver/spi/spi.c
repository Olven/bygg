/*
 * spi.c
 *
 * Created: 27.10.2017 11:34:31
 *  Author: sondstaf
 */

#include <stdio.h>
#include <avr/io.h>
#include "spi.h"


void spi_init()
{
	DDRB |= (1 << DDB7);
	PORTB |= (1 << DDB7);
	
}
