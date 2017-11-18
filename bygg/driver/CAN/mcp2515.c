/*
 * CFile2.c
 *
 * Created: 27.10.2017 15:44:10
 *  Author: sondstaf
 */

#include <stdlib.h>
#include <avr/io.h>
#include <stdio.h>


#include "spi.h"
#include "mcp2515.h"



uint8_t mcp2515_Read(uint8_t address)
{

	spi_chipselect(1);
	spi_send(MCP_READ); // SPI instruction for Read 0000 0011b, 0x03h
	spi_send(address);

	uint8_t testData = spi_read();
	spi_chipselect(0);
	return testData;
}

void mcp2515_Write(uint8_t address, uint8_t data)
{
	spi_chipselect(1);
	spi_send(MCP_WRITE);
	spi_send(address);
	spi_send(data);

	spi_chipselect(0);
}

void mcp2515_Request_to_Send(uint8_t reg)
{
    // Request to send from buffer..
    // Command is 1000 0NNNb.
    // Where NNN is 1|0 and spesifies which buffer to request transmission.

    spi_chipselect(1);
    spi_send(reg);
    spi_chipselect(0);
}

uint8_t mcp2515_Read_Status()
{
    uint8_t mcp_status;
    spi_chipselect(1);
    // Read status 0b1010 0000 = 0xA0 = MCP_READ_STATUS;
    spi_send(MCP_READ_STATUS);
    mcp_status = spi_read();    // Returns statusbits for transmit and revice functions.
    spi_chipselect(0);

    return mcp_status;
}

void mcp2515_BitMod(uint8_t address, uint8_t mask, uint8_t data)
{
    // Send an address, a mask and data, the chip will then change the
    // byte in the address using the mask and input data.
    // 1 in mask = change, 0 = do not change.
    // Data spesifies the value we want the bit to change too: 1|0.

    spi_chipselect(1);

    spi_send(MCP_BITMOD);
    spi_send(address);
    spi_send(mask);
    spi_send(data);

    spi_chipselect(0);
}

void mcp2515_Reset()    // Resets the internal regiserts of mcp2515 chip,
{                       // Set it in config mode..
    spi_chipselect(1);
    spi_send(MCP_RESET);
    spi_chipselect(0);
}
