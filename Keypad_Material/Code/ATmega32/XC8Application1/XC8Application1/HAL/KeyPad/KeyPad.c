/*
 * KeyPad.c
 *
 * Created: 3/17/2024 9:47:34 PM
 *  Author: Mahmoud Khaled
 */ 
#include "KeyPad.h"

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

uint8 KP_GetPressed(void)
{
	uint8 row_counter, column_counter, Btn=0;
	Dio_state_t Btn_state;
	
	for (row_counter = 0; row_counter < KEYPAD_ROWS; row_counter++)
		Dio_Write(keypad_rows_pins[row_counter], KEYPAD_DISABLE_LOGIC);
	
	/* Scanning */
	for (row_counter = 0; row_counter < KEYPAD_ROWS; row_counter++)
	{
		Dio_Write(keypad_rows_pins[row_counter], KEYPAD_ENABLE_LOGIC);
		for (column_counter = 0; column_counter < KEYPAD_COLUMNS; column_counter++)
		{
			Btn_state = Dio_Read(keypad_columns_pins[column_counter]);
			/* Identifying */
			if (KEYPAD_ENABLE_LOGIC == Btn_state)
			{
				/* Encoding */
				Btn = KP_Maparr[row_counter][column_counter];
			}
						
		}
		Dio_Write(keypad_rows_pins[row_counter], KEYPAD_DISABLE_LOGIC);
	}
	
	return Btn;
}