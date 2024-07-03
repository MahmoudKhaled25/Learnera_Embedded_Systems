/*
 * KeyPad_Config.h
 *
 * Created: 3/17/2024 9:47:22 PM
 *  Author: Mahmoud Khaled
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/*************************************** Includes ***************************************/
#include "../../MCAL/DIO/Dio.h"

/**************************************** Macros ****************************************/
#define KEYPAD_ACTIVE_HIGH 0
#define KEYPAD_ACTIVE_LOW  1

#define CONFIG_ENABLE   1
#define CONFIG_DISABLE  0 

/* Keypad Configuration */
#define KEYPAD_COLUMNS  3
#define KEYPAD_ROWS     4
#define KEYPAD_TYPE		KEYPAD_ACTIVE_HIGH

/* Pre-Compiled Configurations */
#if (KEYPAD_ROWS==4) && (KEYPAD_COLUMNS==4)
#define KEYPAD_4X4_CONFIG CONFIG_ENABLE
#define KEYPAD_4X3_CONFIG CONFIG_DISABLE
#elif (KEYPAD_ROWS==4) && (KEYPAD_COLUMNS==3)
#define KEYPAD_4X4_CONFIG CONFIG_DISABLE
#define KEYPAD_4X3_CONFIG CONFIG_ENABLE
#else
#define KEYPAD_4X4_CONFIG CONFIG_DISABLE
#define KEYPAD_4X3_CONFIG CONFIG_DISABLE
#error Undefined Keypad Configuration
#endif // KEYPAD_CONFIG

#if KEYPAD_TYPE == KEYPAD_ACTIVE_HIGH
#define KEYPAD_ENABLE_LOGIC  HIGH
#define KEYPAD_DISABLE_LOGIC LOW
#else
#define KEYPAD_ENABLE_LOGIC  LOW
#define KEYPAD_DISABLE_LOGIC HIGH
#endif // KEYPAD_TYPE


/********************************** Global Declaration **********************************/
extern channel_t keypad_rows_pins[KEYPAD_ROWS];
extern channel_t keypad_columns_pins[KEYPAD_COLUMNS];


#endif /* KEYPAD_CONFIG_H_ */