/*
 * can.c
 *
 * Created: 22.11.2017 17:14:35
 *  Author: sondstaf
 */ 

#include <stdio.h>
#include <avr/io.h>
#include <stdlib.h>

#include "mcp2515.h"
#include "can.h"
/*
void can_init()
{
    mcp2515_Reset();

    MODE_LOOPBACK;
    //mcp2515_BitMod(MCP_CANCTRL, 0b11100000, MODE_LOOPBACK)     // Set MCP in loopback mode. Used for test purposes.


}


void can_message_send(CAN_msg)
{
    /*
   while(mcp2515_bit_test(MCP_TXB0CTRL__TEST_TX_REQUEST)){}
    mcp2515_write(msg.id >> 3,  MCP_TXB0_SIDH);
    mcp2515_write(msg.id << 5,  MCP_TXB0_SIDL);
    mcp2515_write(msg.length,   MCP_TXB0_DLC);
    for(int i = 0; i < msg.length; i++){
        mcp2515_write(msg.data.bytes[i], MCP_TXB0_D0 + i);
    }
    mcp2515_request_to_send(MCP_RTS_TXB0);
    
/*
void can_error()
{

}
void can_transmit_complete()
{

}

void can_data_receive()
{
    /*
    can_msg_t msg;
    memset(&msg, 0, sizeof(can_msg_t));
    if(mcp2515_bit_test(MCP_CANINTF__TEST_RX0_FULL)){
        msg.id      = (mcp2515_read(MCP_RXB0_SIDH) << 3) | (mcp2515_read(MCP_RXB0_SIDL) >> 5);
        msg.length  = (mcp2515_read(MCP_RXB0_DLC)) & (0x0f);
        for(int i = 0; i < msg.length; i++){
            msg.data.bytes[i] = mcp2515_read(MCP_RXB0_D0 + i);
        }
        mcp2515_BitMod(MCP_CANINTF__SET_RX0_CLEAR);
    } else {
        msg.id = CANID_None;
    }
    return msg;
    
}


void can_int_vect()
{

}
*/