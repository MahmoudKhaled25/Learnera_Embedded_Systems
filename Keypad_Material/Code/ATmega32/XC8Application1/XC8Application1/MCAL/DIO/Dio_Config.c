/*
 * Dio_Config.c
 *
 *  Created on: 14 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */
#include "Dio_Config.h"

Dio_pin_config pin[PIN_COUNT]={
		// Keypad Rows Pins
		{PORT_C,PIN_0,OUTPUT},
		{PORT_C,PIN_1,OUTPUT},
		{PORT_C,PIN_2,OUTPUT},
		{PORT_C,PIN_3,OUTPUT},
		
		// Keypad Columns Pins
		{PORT_C,PIN_4,INPUT},
		{PORT_C,PIN_5,INPUT},
		{PORT_C,PIN_6,INPUT},
		
		// Debugging LEDs
		{PORT_D,PIN_0,OUTPUT},
		{PORT_D,PIN_1,OUTPUT},
		{PORT_D,PIN_2,OUTPUT},
		{PORT_D,PIN_3,OUTPUT}
};

