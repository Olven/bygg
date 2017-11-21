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

void joystick_calibrate()       // Calibration is not realy needed, values given without calibration are nicely
                                // Given from [0, 255].
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


struct buttonpressed buttonstate(){

	button.leftbutton =((PINB & (1 << PB1)));
	button.rightbutton = ((PINB & (1 << PB2)));
	button.joystickbutton = (!(PINB & (1 << PB0)));
	return button;

}
// Input from the adc is given in the range [0, 255], functions below converts
// read and convert the values.
struct joystick_position_t joystick_getPosition()		// Returns the position withing the following cordinated.[-100, 100]
{
	joystick_pos.x_dir = ADC_read(joystick_x);
	joystick_pos.y_dir = ADC_read(joystick_y);
	joystick_pos.x_dir = (joystick_pos.x_dir - 127)/1.27;
	joystick_pos.y_dir = (joystick_pos.y_dir - 127)/1.27;
	return joystick_pos;

}

struct joystick_position_t joystick_getSliderPosition()		// Returns the position withing the following cordinated [-100, 100]
{
		joystick_pos.x_dir = ADC_read(joystick_slider_x);
		joystick_pos.y_dir = ADC_read(joystick_slider_y);
		joystick_pos.x_dir = (joystick_pos.x_dir - 127)/1.27;
		joystick_pos.y_dir = (joystick_pos.y_dir - 127)/1.27;
		return joystick_pos;
}


joystick_direction_t joystick_getDirection()	// Returns the direction off the joystick or slider
{
	static joystick_direction_t previous;

	/*
	Vi brukar threshold for � unng� at retningen hoppar mellom n�ytral og kva retning joysticken har.
	Etter det brukar vi ei if-else l�kke for � bestemme retning, der x-aksen har prioritet over y-aksen, sidan den blir testa f�rst.
	Om retningen havnar innan for omr�det mellom threshholdet, brukar vi den forgje retingen som var angitt.

	Funksjonen returnerer ein verdi, gitt fr� enum joystick_direction_t
    //TODO: Convert to switch-case?
	*/
	joystick_getPosition();

	int Dir_threshold = 80;
	int Neutral_threshold = 40;

	if(joystick_pos.x_dir > Dir_threshold)
	{
		joystick_dir = Right;

	}
	else if (joystick_pos.x_dir < -Dir_threshold)
	{
		joystick_dir = Left;

	}
	else if(joystick_pos.y_dir > Dir_threshold)
	{
		joystick_dir = Up;

	}
	else if (joystick_pos.y_dir < -Dir_threshold)
	{
		joystick_dir = Down;

	}
	else if(abs(joystick_pos.x_dir) < Neutral_threshold && abs(joystick_pos.y_dir) < Neutral_threshold)
	{
		joystick_dir = Neutral;

	}
	else
	{
		joystick_dir = previous;
	}

	previous = joystick_dir;

	return joystick_dir;
}




const char* getDirection()	// getDirection returnera ein chararray som beskriv retningen basert p� verdien fr� joystick_getDirection().
{
	switch(joystick_getDirection())
	{
		case Left: return "Left";
		case Right: return "Right";
		case Up: return "Up";
		case Down: return "Down";
		case Neutral: return "Neutral";
		default: return "Neutral";
	}
}
