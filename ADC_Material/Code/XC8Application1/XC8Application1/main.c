#include "main.h"

uint16 volt, oldVolt;

int main()
{
	Dio_init();
	ADC_Init(VREF_AVCC, ADC_SCALER_64);
	LCD_Init();
	
	while (1)
	{
		volt = ADC_ReadVolt(CH_0);
		
		if (volt != oldVolt)
		{
			LCD_Clear();
			LCD_PrintNum(volt/1000);
			LCD_PrintChar('.');
			LCD_PrintNum(volt%1000);

			oldVolt = volt;
		}
	}
}