/*
 * Dio_Config.c
 *
 *  Created on: 14 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */
#include "Dio_Config.h"

Dio_pin_config pin[PIN_COUNT]={
		// LCD Pins
		{PORT_C,PIN_0,OUTPUT},
		{PORT_C,PIN_1,OUTPUT},
		{PORT_C,PIN_2,OUTPUT},
		{PORT_C,PIN_3,OUTPUT},
		{PORT_C,PIN_4,OUTPUT},
		{PORT_C,PIN_5,OUTPUT},
		// ADC Pin	
		{PORT_A, PIN_0, INPUT}
};

