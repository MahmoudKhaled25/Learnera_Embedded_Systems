/*
 * KeyPad.c
 *
 *  Created on: 18 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */

#include "KeyPad.h"

/* Encoding */
static const uint8 KP_Maparr[KEYPAD_ROWS][KEYPAD_COLUMNS] = 
{
#if KEYPAD_4X4_CONFIG==CONFIG_ENABLE
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
	{'1', '2', '3', '-'},
	{'c', '0', '=', '+'}
#elif KEYPAD_4X3_CONFIG==CONFIG_ENABLE
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
	{'*', '0', '#'}
#endif
};

uint8 KP_GetPressed()
{
	uint8 row_counter, column_counter;
	Dio_state_t state=LOW;
	uint8 Btn=0;
	
	for(row_counter=0; row_counter<KEYPAD_ROWS ; row_counter++)
		Dio_Write(keypad_rows_pins[row_counter], KEYPAD_DISABLE_LOGIC);
	
	for(row_counter=0; row_counter<KEYPAD_ROWS ; row_counter++)
	{
		/* Scanning */
		Dio_Write(keypad_rows_pins[row_counter], KEYPAD_ENABLE_LOGIC);
		for (column_counter = 0; column_counter < KEYPAD_COLUMNS; column_counter++)
		{
			state = Dio_Read(keypad_columns_pins[column_counter]);
			if (KEYPAD_ENABLE_LOGIC == state)
				/* Identifying Pressed Key */
				Btn = KP_Maparr[row_counter][column_counter];
		}
		Dio_Write(keypad_rows_pins[row_counter], KEYPAD_DISABLE_LOGIC);
	}

	return Btn;
}
