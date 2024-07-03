/*
 * main.c
 *
 * Created: 3/8/2024 10:18:09 AM
 *  Author: Mahmoud Khaled
 */ 

#include "main.h"

uint8 Pressed_Btn;

int main(void)
{
	Dio_init();
	
	
	while (1)
	{
		Pressed_Btn = KP_GetPressed();
		
		if (Pressed_Btn)
		{
			uint8 num = Pressed_Btn - '0';
			Dio_Write(PORTD_0, (num >> 0) & 0x01);
			Dio_Write(PORTD_1, (num >> 1) & 0x01);
			Dio_Write(PORTD_2, (num >> 2) & 0x01);
			Dio_Write(PORTD_3, (num >> 3) & 0x01);
		}
	}
}