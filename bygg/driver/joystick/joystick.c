/*
 * joystick.c
 *
 * Created: 15.09.2017 11:48:36
 *  Author: sondstaf
 */ 
#include <stdio.h>
#include <avr/io.h>
#include <stdbool.h>
#include "joystick.h"
#include "../adc/adc.h"
//#include <avr/delay.h>

//static uint8_t center_x;
//static uint8_t center_y;


void joystick_init()
{	
	joystick_calibrate();
}

void joystick_calibrate()
{
	printf("Calibration of the joystick...\n");
	
	DDRB &= ~((1 << PB0)|(1 << PB1)|(1 << PB2));
	printf("Choose x max\n");
	while(!(PINB & (1 << PB1))){
		
	}
	int max_x = ADC_read(joystick_x);

	while((PINB & (1 << PB1))){
		
	}
	printf("Choose x min\n");
	while(!(PINB & (1 << PB1))){
		
	}
	int min_x = ADC_read(joystick_x);
	while((PINB & (1 << PB1))){
		
	}
	
	int range_x = max_x-min_x;
	int mean_x = 0.5*range_x;
	printf("Choose y max\n");
	while(!(PINB & (1 << PB1))){
		
	}
	int max_y = ADC_read(joystick_y);
	while((PINB & (1 << PB1))){
		
	}
	printf("Choose y min\n");
	while(!(PINB & (1 << PB1))){
		
	}
	int min_y = ADC_read(joystick_y);
	
	int range_y = max_y-min_y;
	int mean_y = 0.5*range_y;
	//center_x = ADC_read(joystick_x);
	//center_y = ADC_read(joystick_y);
	printf(" range_x is %d \n", range_x);
	printf(" range_y is %d \n", range_y);
	printf(" mean_x is %d \n", mean_x);
	printf(" mean_y is %d \n", mean_y);
	
}

bool joystick_button(int button)
{
	
}

struct joystick_position_t joystick_getPosition()
{
	pos.x_dir = ADC_read(joystick_x);
	pos.y_dir = ADC_read(joystick_y);
	return pos;
	
}


joystick_direction_t joystick_getDirection()
{
	
}
