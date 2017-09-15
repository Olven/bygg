/*
 * UART.c
 *
 * Created: 08.09.2017 09:20:46
 *  Author: sondstaf
 */ 

#define F_CPU 4915200UL
#define BAUD 9600
#define MYBURR F_CPU/16/BAUD-1
//#define stdio = fdevopen(uart_transmit(), uart_receive());


//#define stdin = FDEV_SETUP_STREAM(uart_transmit, uart_receive, _FDEV_SETUP_RW);

#include <stdio.h>
#include <avr/io.h>
#include "uart.h"




// PD0 is used as the UART Receiver, and PD1 as Transmitter.



void uart_init(void)
{

	UBRR0L = MYBURR;

	
	//UCSR0B = (1<<RXEN)|(1<<TXEN); //Enables receiver and transmitter
	//UCSR0C = (1<<URSEL0)|(1<<UCSZ00)|(1<<UCSZ10); //set frame formal :8data, 2stop bit
	
	// USART Control and Status
	// UCSRB 
	UCSR0B  |=  (1<<RXEN0); // receive enable
	UCSR0B	|=	(1<<TXEN0); // transmit enable


	// Declare printf = uart_transmit and scanf = uart_recive
	fdevopen(uart_transmit, uart_receive);
}


void uart_transmit(uint8_t data)
{
	while(!(UCSR0A & (1<<UDRE0))); //wait for empty transmit buffer
	UDR0 = data;

}

uint8_t uart_receive()
{
	while ( !((UCSR0A) & (1<<RXC0)) ); //wait for data to be received
	return UDR0; //Get and return received data from buffer
	
}