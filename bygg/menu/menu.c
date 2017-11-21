

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <avr/delay.h>

#include "../driver/oled/oled.h"
#include "menu.h"

#include "../driver/joystick/joystick.h"


static uint8_t current_position = 0;
uint8_t previous_position = 0;


void build_main(){
	menu main_menu;
	menu options;
	menu new_game;

	strcpy(main_menu.title, "Hovedmeny");
	main_menu.parent = NULL;
	//main_menu.child-> new_game;

}


void menu_init()
{

}


uint8_t get_current_position()
{
	return current_position;
}

void create_menu()
{

}

/*
Old version of the menu..
void create_menu(menu* m)
{
	const char *words[4] = {"Main menu", "Play game", "Options","End game" };
	uint8_t i = 0;
	for(i = 0; i < m->length; i = i + 1){
		build_menu(m->pos[i],i);
	}

}
const char *first[4] = {"Main menu", "Play game", "Options","End game" };
create_menu(first,4);

void create_menu(char words*, length)
{

	uint8_t i = 0;
	for(i = 0; i < length; i = i + 1){
		build_menu(words[i],i);
	}

}
*/
void build_menu(menu menu_to_build, int page)
{
	oled_write_cmd(0x00);
	oled_write_cmd(0x10);
	oled_goto_page(page);


	printf(menu_to_build.title);

}

void draw_cursor(uint8_t pos)
{

	current_position = current_position + pos;
	oled_goto_page(current_position);
	oled_write_cmd(0x03);
	oled_write_cmd(0x13);
	printf("<");
}


void remove_cursor() //remove cursor from position
{
	oled_goto_page(current_position);
	oled_write_cmd(0x03);
	oled_write_cmd(0x13);
	printf(" ");					// Remove cursor from previous position.
}


void move_cursor() //takes x and y values from joystick to move cursor up and down in the menu
{
	uint8_t pos;
	if(joystick_getDirection() == Up)
	{
		remove_cursor();				// Remove cursor from previous position.
		if(current_position == 0)
		{
			pos = 7;
		}
		else
		{
			pos = -1;
		}
	draw_cursor(pos);
	}
	else if(joystick_getDirection() == Down)
	{
		remove_cursor();				// Remove cursor from previous position.
		if(current_position == 7)
		{
			pos = -7;
		}
		else
		{
			pos = 1;
		}
		draw_cursor(pos);
	}
	else
	{
		pos = 0;
	}
}
