/*
 * SPIdriver.c
 *
 * Created: 27.10.2017 15:47:01
 *  Author: sondstaf
 */

#include <stdlib.h>
#include <avr/io.h>
#include <stdio.h>

void spi_init(){

	// Bit 7 definera SCK og Bit 6 definera Master Output Slave Input.

	DDRB = (1 << DDB7)|(1 << DDB5)|(1 << DDB4);
	DDRB &= ~(1 << DDB6);
	/*SPDR: SPI Data Register */
	/*SPSR: SPI Status Register */
	/*SPCR:	SPI Control Register */

	SPCR |= (1 << MSTR);	// Define our microchip as master and the other as slave in the SPI interface.
	SPCR |= (1 << SPR0);	// Define clock pulses.
	SPCR |= (1 << SPE);		// Activate SPI interface.


	/*
	SPCR bit definitions

	#define SPIE	7
	#define SPE	    6
	#define DORD	5
	#define MSTR	4
	#define CPOL	3
	#define CPHA	2
	#define SPR1	1
	#define SPR0	0
	*/

}

uint8_t spi_send(uint8_t cData){

	// Output data in the Data Register.
	SPDR = cData;
	//Wait for transmission to complete
	while(!(SPSR & (1<<SPIF))){}

}

uint8_t spi_read(){ //When master sends information, it sends a dummy bit first!

	spi_send(0xFF); // Dummy byte, we need to send data to the MCP to read data with SPI.

	//Wait for reception to complete
	while(!(SPSR & (1<<(SPIF)))){}

	return SPDR;

}

void spi_chipselect(uint8_t select)     // Chip select.
{
	if (select == 0){
		PORTB |= (1<<PB4);
	}
	else{
		PORTB &= ~(1<<PB4);
	}
}
