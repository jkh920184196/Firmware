/*
 * Solomon Systech SSD1305 Interface
 * 
 * @Company
 *   1o1 Oscilloscope Team
 * 
 * @File Name
 *   ssd1305.c
 * 
 * @Summary
 *   Interface to control SSD1305 based OLED display. Written for Electronic
 *   Assembly GmbH EA W096064-XALG display on 1o1 v1.0 board.
*/

#include "ssd1305.h"
#include "ports.h"
#include "sw_timer.h"

void
ssd1305_init()
{
	OLED_RES_TRIS = PORT_OUTPUT;
	OLED_RES_PORT = 0;
	OLED_RES_LAT = HIGH;
}


void
ssd1305_enable()
{
	OLED_RES_LAT = HIGH;
    sw_timer wait_init = TIMER(32);
    while (!tmr_expired(wait_init)) {}
    
    pmp_6800_write_command(0x40);
	pmp_6800_write_command(0xA6);
	pmp_6800_write_command(0x81);
	pmp_6800_write_command(0x7F);
	pmp_6800_write_command(0xD5);
	pmp_6800_write_command(0x40);
	pmp_6800_write_command(0xD9);
	pmp_6800_write_command(0x44);
	pmp_6800_write_command(0xA1);
	pmp_6800_write_command(0xC8);
	pmp_6800_write_command(0xAF);
}

void
ssd1305_disable()
{
	OLED_RES_LAT = LOW;
}