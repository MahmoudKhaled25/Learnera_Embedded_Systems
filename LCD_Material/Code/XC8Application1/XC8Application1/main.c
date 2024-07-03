#include "main.h"

int main()
{
	Dio_init();
	LCD_Init();
	
	LCD_SetCursor(1,5);
	LCD_PrintString("Hello, World!");
	_delay_ms(2000);
	LCD_ShiftLeft();
	_delay_ms(2000);
	LCD_ShiftLeft();
	
	while (1)
	{
		
	}
}