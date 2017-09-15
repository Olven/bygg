/*
 * adc.h
 *
 * Created: 15.09.2017 11:49:10
 *  Author: sondstaf
 */ 


#ifndef ADC_H_
#define ADC_H_

typedef enum
{
	joystick_x = 0x0004,
	joystick_y = 0x0005,
	joystick_slider_x = 0x0006,
	joystick_slider_y = 0x0007,
}channel;


uint8_t ADC_read(channel input);



#endif /* ADC_H_ */