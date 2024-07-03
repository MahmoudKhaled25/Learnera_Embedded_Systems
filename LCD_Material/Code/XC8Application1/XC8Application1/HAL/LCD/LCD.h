/*
 * LCD_Interface.h
 *
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*********************************************** Include Section *****************************************/
#include "Dio.h"
#include "LCD_cfg.h"


/*********************************************** Function declaration ************************************/
void LCD_Init(void);
void LCD_Clear(void);
void LCD_PrintChar(c8 c);
void LCD_PrintString(const c8 *s);
void LCD_SetCursor(uint8 row , uint8 column);  // row 1:2  , column 1:16
void LCD_MoveCursorRight(void);
void LCD_MoveCursorLeft(void);
void LCD_ShiftRight(void);
void LCD_ShiftLeft(void);
#endif /* LCD_INTERFACE_H_ */