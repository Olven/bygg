/*
 * UART.h
 *
 * Created: 08.09.2017 09:20:53
 *  Author: sondstaf
 */ 


#ifndef UART_H_
#define UART_H_

void uart_init(void);
void uart_transmit(uint8_t data);
uint8_t uart_receive(void);
//int(*)(struct_file*) uart_transmit(uint8_t data);
//int(*)(struct_file*) uart_receive(void);

#endif /* UART_H_ */