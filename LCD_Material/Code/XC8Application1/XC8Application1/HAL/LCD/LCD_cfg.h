/*
 * LCD_cfg.h
 *
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_


/********************************************* Marco section *******************************************/
#define _8_bit			  1
#define _4_bit			  0


/******************************************** Mode config *********************************************/
#define MODE _4_bit


/********************************************* Pin Config *********************************************/

/************ 4_bit_initialization ************/
#define LCD_D7            PORTC_5
#define LCD_D6			  PORTC_4
#define LCD_D5			  PORTC_3				
#define LCD_D4			  PORTC_2  

#if MODE == _8_bit
#define LCD_D3            PORTA_3
#define LCD_D2			  PORTA_2
#define LCD_D1			  PORTA_1
#define LCD_D0 			  PORTA_0
#endif

#define LCD_EN 			  PORTC_1
#define LCD_RS			  PORTC_0 



/********************************************* Initialization Config *******************************/


/*************** FUNCTION SET  ****************/                                  
#if MODE==_4_bit
#define FUNC_SET_VALUE    0x28 
#elif MODE==_8_bit
#define FUNC_SET_VALUE    0x38 
#endif
     

/*************** DISPLAY ON/OFF ***************/ 
//   For cursor OFF						  (0x0C)   
//   For cursor ON						  (0x0E)   
//   For cursor ON and Blinking			  (0x0F)
#define DIS_ON_OFF_VALUE  0x0C       


/***************** ENTRY MODE *****************/
//   For shifting cursor to left          (0x04)
//   For shifting cursor to right		  (0x06)
//	 For shifting all characters to left  (0x07)
//	 For shifting all characters to right (0x05)
#define ENTRY_MODE_VALUE  0x06

/********************************************* miscellaneous commands *******************************************/
#define CURSOR_LEFT       0X10  
#define CURSOR_RIGHT      0x14
#define SHIFT_LEFT		  0x18
#define SHIFT_RIGHT		  0x1C
#define DISPLAY_OFF       0x08
#define DISPLAY_ON		  0x0c
#define CLEAR_DISPLAY     0x01
/*****************************************************************************************************/


#endif /* LCD_CFG_H_ */