/*
 * CANdriver.h
 *
 * Created: 27.10.2017 15:46:01
 *  Author: sondstaf
 */


#ifndef CANDRIVER_H_

void can_init();
void can_message_send();
void can_error();
void can_transmit_complete();
void can_data_receive();
void can_int_vect();

#define CANDRIVER_H_





#endif /* CANDRIVER_H_ */
