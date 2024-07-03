/*
 * KeyPad_Config.c
 *
 * Created: 3/17/2024 9:47:59 PM
 *  Author: Mahmoud Khaled
 */ 
#include "KeyPad_Config.h"

channel_t keypad_rows_pins[KEYPAD_ROWS] = {
	// Rows Pins
	PORTC_0,
	PORTC_1,
	PORTC_2,
	PORTC_3
};

channel_t keypad_columns_pins[KEYPAD_COLUMNS] = {
	// Columns Pins
	PORTC_4,
	PORTC_5,
	PORTC_6
};