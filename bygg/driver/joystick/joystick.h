/*
 * joystick.h
 *
 * Created: 15.09.2017 11:48:48
 *  Author: sondstaf
 */ 
#include <stdint.h>

#ifndef JOYSTICK_H_
#define JOYSTICK_H_

typedef int joystick_position_t;
typedef int joystick_direction_t;

void joystick_init();

void joystick_calibrate();

//bool joystick_button(int button);

struct joystick_position_t joystick_getPosition();

joystick_direction_t joystick_getDirection();

struct joystick_position_t
{
	uint8_t x_dir;
	uint8_t y_dir;
}pos;

struct joystick_direction_t
{
	
};

#endif /* JOYSTICK_H_ */