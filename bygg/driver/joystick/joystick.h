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
typedef char joystick_direction_t;



void joystick_init();

void joystick_calibrate();



//bool joystick_button(int button);

struct joystick_position_t joystick_getPosition();

struct joystick_position_t joystick_getSliderPosition();

joystick_direction_t joystick_getDirection();

struct buttonpressed buttonstate();

const char* getDirection();

struct buttonpressed
{
	int leftbutton;
	int rightbutton;
	int joystickbutton;
}button;
	

struct joystick_position_t
{
	int x_dir;
	int y_dir;
}joystick_pos;

enum joystick_direction_t
{
	Right,
	Left,
	Up,
	Down,
	Neutral
}joystick_dir;

#endif /* JOYSTICK_H_ */