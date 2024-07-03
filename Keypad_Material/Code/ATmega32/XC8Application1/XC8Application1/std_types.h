/*
 * std_types.h
 *
 * Created: 3/8/2024 10:25:46 AM
 *  Author: Mahmoud Khaled
 */ 
#ifndef STD_TYPES_H
#define	STD_TYPES_H

/*.................. section:includes ..................*/

/*............... section:macro declaration ...............*/
#define ZERO_INIT        0

#define E_OK       1
#define E_NOT_OK   0

/*............. section:data type declaration ..........*/

typedef unsigned char        uint8;
typedef unsigned short       uint16;
typedef unsigned long        uint32;

typedef signed char          sint8;
typedef signed short         sint16;
typedef signed long          sint32;

//#define NULL         (void)(0)


typedef uint8     Std_ReturnType;

#endif	/* STD_TYPES_H */

