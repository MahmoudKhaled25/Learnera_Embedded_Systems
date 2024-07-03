/*
 * KeyPad.h
 *
 * Created: 3/17/2024 9:47:06 PM
 *  Author: Mahmoud Khaled
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/*************************************** Includes ***************************************/
#include "../../MCAL/DIO/Dio.h"
#include "KeyPad_Config.h"

/********************************* Functions Declaration ********************************/

/**
 * @brief Function to get the pressed key from the keypad.
 * 
 * @return uint8 The value of the pressed key.
 */
uint8 KP_GetPressed(void);
#endif /* KEYPAD_H_ */