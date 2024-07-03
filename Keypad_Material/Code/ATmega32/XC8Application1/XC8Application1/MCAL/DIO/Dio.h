#ifndef DIO_H_
#define DIO_H_

/*................... section:includes ....................*/
#include <avr/io.h>
#define F_CPU 1E6
#include <util/delay.h>
#include "../../Bit_math.h"
#include "../../std_types.h"
#include "Dio_types.h"
#include "Dio_Config.h"

/*............... section:macro declaration ...............*/

/*.............. section:data type declaration ............*/

/*.............. section:functions declaration ............*/
void Dio_init();
void Dio_Write(channel_t ch,Dio_state_t state);
void Dio_Pin_Toggle(channel_t ch);
Dio_state_t Dio_Read(channel_t ch);



#endif
