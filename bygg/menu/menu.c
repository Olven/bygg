/*
 * menu.c
 *
 * Created: 13.10.2017 14:23:57
 *  Author: sondstaf
 */ 

#include <stdlib.h>
#include <stdint.h>

#include "../driver/oled/oled.h"
#include "menu.h"
/*#include "../drive/joystick/joystick.h"*/


volatile uint8_t current_position = 0;
volatile uint8_t previous_position = 0;

void menu_init()
{

	
}

void create_menu()
{
	const char *words[4] = {"Main menu", "Play game", "Options","End game" };
		
	uint8_t i = 0;
	for(i = 0; i < 4; i = i + 1){
		build_menu(words[i],i);
	}
	
}

void build_menu(char *menu_title, int page)
{
	oled_write_cmd(0x00);
	oled_write_cmd(0x10);
	oled_goto_page(page);


	printf(menu_title);

}

void draw_cursor()
{
	
	oled_write_cmd(0x03);
	oled_write_cmd(0x13);
	printf(" ");					// Remove cursor from previous position.
	oled_goto_page(current_position);
	printf("<");
}

void set_cursor_position(int pos)
{
	current_position = current_position + pos;
}

void get_cursor_position()
{
	return current_position;
}