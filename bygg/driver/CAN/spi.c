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
	
	// Bit 7 definera SCK og Bit 6 definera Master Output Slave Input. (Kanskje bytte ut 6 med 5?)
	DDRB = (1 << DDB7)|(1 << DDB5)|(1 << DDB4);
	DDRB &= ~(1 << DDB6);
	/*SPDR: SPI Data Register */
	/*SPSR: SPI Status Register */
	/*SPCR:	SPI Control Register */

	SPCR |= (1 << MSTR);	// Vel vår SPI som Storbonde over den andre Drengen. AKA Høvding/Trell
	SPCR |= (1 << SPR0);	// Set antal klokkeslag for klokkesignalet som skal sendast. SPR0 = 1 gir Fosc/16.
	SPCR |= (1 << SPE);		// Aktiver SPI Grensesnitt
	
	
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

	
	SPDR = cData;
	//Wait for transmission to complete
	while(!(SPSR & (1<<SPIF))){}
	
}

uint8_t spi_read(){ //When master sends information, it sends a dummy bit first!

	spi_send(0xFF); //dummy byte

	//uint8_t *data = 1;
	//SPDR = data;
	//Wait for reception to complete
	while(!(SPSR & (1<<(SPIF)))){}
	
	return SPDR;
	
}

void spi_chipselect(uint8_t select){
	if (select == 0){
		PORTB |= (1<<PB4);
	} 
	else{
		PORTB &= ~(1<<PB4);
	}
}