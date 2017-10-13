/*
 * CFile1.c
 *
 * Created: 29.09.2017 15:05:15
 *  Author: sondstaf
 */

#include "oled.h"
#include "../uart.h"
#include <stdio.h>
#include <avr/pgmspace.h>
#include "fonts/fonts.h"


uint8_t page, column;

#define ASCII_OFFSET 32



void oled_init()
{

	oled_write_cmd(0xAE);		//  display  off
    oled_write_cmd(0xA1);       //segment  remap
    oled_write_cmd(0xDA);       //common  pads  hardware:  alternative
    oled_write_cmd(0x12);
    oled_write_cmd(0xC8);       //common output scan direction:com63~com0
    oled_write_cmd(0xA8);       //multiplex  ration  mode:63
    oled_write_cmd(0x3F);
    oled_write_cmd(0xD5);       //display divide ratio/osc. freq. mode
    oled_write_cmd(0x80);
    oled_write_cmd(0x81);       //contrast  control
    oled_write_cmd(0x50);
    oled_write_cmd(0xD9);       //set  pre-charge  period
    oled_write_cmd(0x21);
    oled_write_cmd(0x20);       //Set  Memory  Addressing  Mode
    oled_write_cmd(0x02);
    oled_write_cmd(0xDB);       //VCOM  deselect  level  mode
    oled_write_cmd(0x30);
    oled_write_cmd(0xAD);       //master  configuration
    oled_write_cmd(0x00);
    oled_write_cmd(0xA4);		//out  follows  RAM  content
    oled_write_cmd(0xA6);       //set  normal  display
    oled_write_cmd(0xAF);       //  display  on
	
	oled_write_cmd(0xB0);
	oled_write_cmd(0x0);
	oled_write_cmd(0x10);
	
	
	fdevopen(oled_write_char, NULL);
	
	
}



void oled_clear()
{
	uint8_t i = 0x00;
	uint8_t j = 0x00;
	
	for (i = 0; i < 8; i = i + 1)
	{
		oled_clear_page(i);
	}
	
	oled_home();
}


void oled_home(void) {
	//Reset the page and column
	page = 0;
	column = 0;
	
	//Set the cursor to the start of the screen
	oled_write_cmd(0x21);
	oled_write_cmd(0x00);
	oled_write_cmd(0x7f);
	
	oled_write_cmd(0x22);
	oled_write_cmd(0x00);
	oled_write_cmd(0x7);
}

void oled_menu()
{
	
}

void oled_reset()
{
	oled_clear();
	oled_write_cmd(0x00);
	oled_write_cmd(0x10);
}


void oled_goto_page(uint8_t line)
{
	page = line;
	oled_write_cmd(Set_Page_Address + page);
}

void oled_clear_page(uint8_t line)
{
	page = line;
	oled_write_cmd(Set_Page_Address + page);
	for (int i = 0; i < Display_Width; i = i + 1)
	{
		oled_write_data(0x00);
	}
}

void oled_goto_column(uint8_t col)
{
	column = col;
	
	oled_write_cmd(col);
}

void oled_write_char(char c)
{

	//oled_goto_page(0);
	for(int i = 0; i < 5; i++)	// Font width = 5;
	{
		oled_write_data(pgm_read_byte(&font5[c - ASCII_OFFSET][i]));
	}
}







