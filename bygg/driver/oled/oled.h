

#ifndef OLED_H_
#define OLED_H_

#include <stdint.h>
#include "fonts/fonts.h"

#define ext_oled_cmd	((volatile char*) 0x1000)
#define ext_oled_data	((volatile char*) 0x1200)


#define DISP_HEIGHT					64
#define DISP_WIDTH					128
#define DISP_PAGES					(DISP_HEIGHT/8)

#define Set_Column_Address			0xA0
#define Set_Page_Address			0xB0


static void oled_write_cmd(char c)
{
	*ext_oled_cmd = c;
}

static void oled_write_data(char c)
{
	*ext_oled_data = c;
}


void oled_init();


void oled_clear();

void oled_home();

void oled_menu();

void oled_reset();

void oled_goto_page(uint8_t line);

void oled_clear_page(uint8_t line);

void oled_write_char(char c);

#endif
