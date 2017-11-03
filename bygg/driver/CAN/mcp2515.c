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

void mcp2515_Request_to_Send()
{
	
}

void mcp2515_Read_Status()
{
	
	
}

void mcp2515_BitMod()
{
	
}

void mcp2515_Reset()
{
}
