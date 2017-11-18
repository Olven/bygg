// CAN high level CANdriver

#include <stdio>
#include <avrio>
#include <stdlib>

#include "mcp2515.h"
#include "can.h"

void can_init()
{
    mcp2515_Reset();

    MODE_LOOPBACK;
    mcp2515_BitMod(MCP_CANCTRL, 0b1110 0000, MODE_LOOPBACK)     // Set MCP in loopback mode. Used for test purposes.


}
void can_message_send(CAN_msg)
{
    // send msg id, length and data..
    mcp2515_Request_to_Send();
    MCP_TXB0CTRL
}

void can_error()
{

}
void can_transmit_complete()
{

}
void can_data_receive()
{

}
void can_int_vect()
{

}
