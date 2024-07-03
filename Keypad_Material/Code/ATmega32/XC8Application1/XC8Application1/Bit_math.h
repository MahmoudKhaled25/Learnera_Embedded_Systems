/*
 * Bit_math.h
 *
 * Created: 3/8/2024 10:27:55 AM
 *  Author: Mahmoud Khaled
 */ 

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*................... section:includes ....................*/
#define MASK_PIN    1

/*............... section:macro declaration ...............*/
#define SET_BIT(_REG,PIN)      (_REG=_REG | (MASK_PIN <<PIN))
#define CLEAR_BIT(_REG,PIN)    (_REG=_REG & (~(MASK_PIN<<PIN)))
#define TOGGLE_BIT(_REG,PIN)   (_REG=_REG ^ (MASK_PIN<<PIN))
#define READ_BIT(_REG,PIN)     ((_REG>>PIN)  & MASK_PIN)

/*.............. section:data type declaration ............*/

/*.............. section:functions declaration ............*/





#endif /* BIT_MATH_H_ */