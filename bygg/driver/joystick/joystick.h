/*
 * joystick.h
 *
 * Created: 15.09.2017 11:48:48
 *  Author: sondstaf
 */ 


#ifndef JOYSTICK_H_
#define JOYSTICK_H_

void joystick_init();

void joystick_calibrate();

bool joystick_button(int button);

joystick_position_t joystick_getPosition();

joystick_direction_t joystick_getDirection();


#endif /* JOYSTICK_H_ */