/*
 * KeyPad_Config.h
 *
 *  Created on: 18 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_
/*Section: Includes*/
#include "../../MCAL/Dio/Dio.h"

/*Section: Macros*/
#define KEYPAD_ACTIVE_HIGH 0
#define KEYPAD_ACTIVE_LOW  1

#define CONFIG_ENABLE   0X01
#define CONFIG_DISABLE  0X00

#define TWELVE_BUTTON  12
#define SIXTEEN_BUTTON 16

#define KEYPAD_COLUMNS  3
#define KEYPAD_ROWS     4
#define KEYPAD_TYPE		KEYPAD_ACTIVE_HIGH


#if (KEYPAD_ROWS * KEYPAD_COLUMNS) == SIXTEEN_BUTTON
#define KEYPAD_4X4_CONFIG CONFIG_ENABLE
#define KEYPAD_4X3_CONFIG CONFIG_DISABLE
#elif (KEYPAD_ROWS * KEYPAD_COLUMNS) == TWELVE_BUTTON
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

extern channel_t keypad_rows_pins[KEYPAD_ROWS];
extern channel_t keypad_columns_pins[KEYPAD_COLUMNS];
#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
