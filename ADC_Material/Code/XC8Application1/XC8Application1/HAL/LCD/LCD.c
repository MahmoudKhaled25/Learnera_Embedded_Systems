/********************************** include section *****************************/
#include "LCD.h"
#include "Bit_math.h"
#ifndef F_CPU  // delay include with guard
#define F_CPU 8E6
#include <util/delay.h>
#endif


/********************************* Function Implementation ************************************/
static void LCD_SendCommand(uint8 ins);
static void LCD_SendData(uint8 data);

#if MODE == _8_bit
/***************** 8_bit *******************/
static void LCD_SendCommand(uint8 ins)
{
	// Select command register
	Dio_Write(LCD_RS,LOW);
	// Out data on [DB7:DB0]
	Dio_Write(LCD_D7,READ_BIT(ins,7));
	Dio_Write(LCD_D6,READ_BIT(ins,6));
	Dio_Write(LCD_D5,READ_BIT(ins,5));
	Dio_Write(LCD_D4,READ_BIT(ins,4));
	Dio_Write(LCD_D3,READ_BIT(ins,3));
	Dio_Write(LCD_D2,READ_BIT(ins,2));
	Dio_Write(LCD_D1,READ_BIT(ins,1));
	Dio_Write(LCD_D0,READ_BIT(ins,0));
	// Send enable signal
	Dio_Write(LCD_EN,HIGH);
	_delay_ms(1);
	Dio_Write(LCD_EN,LOW);
	_delay_ms(1);	
}

static void LCD_SendData(uint8 data)
{
	// Select data register
	Dio_Write(LCD_RS,HIGH);
	// Out data on [DB7:DB0]
	Dio_Write(LCD_D7,READ_BIT(data,7));
	Dio_Write(LCD_D6,READ_BIT(data,6));
	Dio_Write(LCD_D5,READ_BIT(data,5));
	Dio_Write(LCD_D4,READ_BIT(data,4));
	Dio_Write(LCD_D3,READ_BIT(data,3));
	Dio_Write(LCD_D2,READ_BIT(data,2));
	Dio_Write(LCD_D1,READ_BIT(data,1));
	Dio_Write(LCD_D0,READ_BIT(data,0));
	// Send enable signal
	Dio_Write(LCD_EN,HIGH);
	_delay_ms(1);
	Dio_Write(LCD_EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(15);
	LCD_SendCommand(FUNC_SET_VALUE);
	_delay_ms(5);
	LCD_SendCommand(FUNC_SET_VALUE);
	_delay_us(100);
	LCD_SendCommand(FUNC_SET_VALUE);
	LCD_SendCommand(FUNC_SET_VALUE);
	LCD_SendCommand(DIS_ON_OFF_VALUE);
	LCD_SendCommand(CLEAR_DISPLAY);
	LCD_SendCommand(ENTRY_MODE_VALUE);
	_delay_ms(1);
}

#elif MODE == _4_bit
/***************** 4_bit *******************/
static void LCD_SendLowNipple(uint8 data);
static void LCD_SendHighNipple(uint8 data);

static void LCD_SendLowNipple(uint8 data)
{
		// Out low nipple of data on [DB7:DB4]
		Dio_Write(LCD_D7,READ_BIT(data,3));
		Dio_Write(LCD_D6,READ_BIT(data,2));
		Dio_Write(LCD_D5,READ_BIT(data,1));
		Dio_Write(LCD_D4,READ_BIT(data,0));
		// Send enable signal
		Dio_Write(LCD_EN,HIGH);
		_delay_ms(1);
		Dio_Write(LCD_EN,LOW);
		_delay_ms(1);
}

static void LCD_SendHighNipple(uint8 data)
{
	// Out high nipple of data on [DB7:DB4]
	Dio_Write(LCD_D7,READ_BIT(data,7));
	Dio_Write(LCD_D6,READ_BIT(data,6));
	Dio_Write(LCD_D5,READ_BIT(data,5));
	Dio_Write(LCD_D4,READ_BIT(data,4));
	// Send enable signal
	Dio_Write(LCD_EN,HIGH);
	_delay_ms(1);
	Dio_Write(LCD_EN,LOW);
	_delay_ms(1);
}

static void LCD_SendCommand(uint8 ins)
{
	// Select command register
	Dio_Write(LCD_RS,LOW);
	LCD_SendHighNipple(ins);
	LCD_SendLowNipple(ins);
}

static void LCD_SendData(uint8 data)
{
	// Select data register
	Dio_Write(LCD_RS,HIGH);
	LCD_SendHighNipple(data);
	LCD_SendLowNipple(data);
}

void LCD_Init(void)
{
	Dio_Write(LCD_RS,LOW);
	_delay_ms(15);
	LCD_SendLowNipple(0x03);
	_delay_ms(5);
	LCD_SendLowNipple(0x03);
	_delay_us(100);
	LCD_SendLowNipple(0x03);
	LCD_SendLowNipple(0x02);
	LCD_SendCommand(FUNC_SET_VALUE);
	LCD_SendCommand(DIS_ON_OFF_VALUE);
	LCD_SendCommand(CLEAR_DISPLAY);
	LCD_SendCommand(ENTRY_MODE_VALUE);
	_delay_ms(1);
}
#endif


void LCD_Clear(void)
{
	LCD_SendCommand(CLEAR_DISPLAY);
	_delay_ms(1);
}

void LCD_PrintChar(c8 c)
{
	LCD_SendData(c);
}

void LCD_PrintString(const c8 *s)
{
	for(uint8 i = 0 ; s[i] ; ++i)
	{
		LCD_SendData(s[i]);
	}
}

void LCD_PrintNum(sint32 n)
{
	c8 Num[10] = {};
	uint8 counter = 0;
	if (n < 0)
	{
		LCD_PrintChar('-');
		n *= -1;
	}
	
	// positive number
	do 
	{
		Num[counter++] = n%10 + '0';
		n /= 10;
	} while (n);
	
	while (counter) 
	{
		LCD_PrintChar(Num[--counter]);
	}
}

void LCD_SetCursor(uint8 row , uint8 column)
{
	if((row-1) == 0)
	{
		LCD_SendCommand(0x80 | (column-1));
	}
	if((row-1) == 1)
	{
		LCD_SendCommand(0x80 | 0x40 | (column-1));
	}
}

void LCD_MoveCursorRight(void)
{
	LCD_SendCommand(CURSOR_RIGHT);
}
void LCD_MoveCursorLeft(void)
{
	LCD_SendCommand(CURSOR_LEFT);
}
void LCD_ShiftRight(void)
{
	LCD_SendCommand(SHIFT_RIGHT);
}
void LCD_ShiftLeft(void)
{
	LCD_SendCommand(SHIFT_LEFT);
}







