/*
 * menu.h
 *
 * Created: 13.10.2017 14:24:14
 *  Author: sondstaf
 */


#ifndef MENU_H_
#define MENU_H_

typedef struct menu menu;
typedef struct menu_item menu_item;


struct menu_item{
	const char* name;
};


struct menu
{
	char title;
	menu *parent;
	struct menu *child;

};

void get_cursor_position();
void move_cursor();
void remove_cursor();

/*
struct menu_builder
{
	char title[]
	int *parent
	char sub_menus[]
};
*/
#endif /* MENU_H_ */
