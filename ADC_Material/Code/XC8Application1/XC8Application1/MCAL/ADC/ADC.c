/*
 * ADC.c
 *
 * Created: 12/18/2023 10:13:50 PM
 *  Author: Mahmoud Khaled
 */ 

/************************************ Include Section ***********************************/
#include "ADC.h"

/************************************ Macros Section ***********************************/
/**
 * @brief: Macro to select ADC reference voltage
 *		- Clear ADC reference voltage bits
 *		- Set ADC reference voltage bits according to VREF
 */	
#define SELECT_VREF(VREF)   ADMUX &= 0x3F;\
							ADMUX |= (((VREF) << 6) & 0xC0)
							
							
/**
 * @brief: Macro to select ADC channel
 *		- Clear ADC channel selection bits
 *		- Set ADC channel selection bits according to CH
 */				
#define SELECT_CH(CH)   ADMUX &= 0xE0;\
						ADMUX |= ((CH) & 0x1F)
						

/**
 * @brief: Macro to select ADC prescaler
 *		- Clear ADC prescaler bits
 *		- Set ADC prescaler bits according to PS
 */	
#define SELECT_PS(PS)  ADCSRA &= 0xF8;\
					   ADCSRA |= ((PS) & 0x07)
						
/********************************** Global Declaration *********************************/
uint16 voltRef;

/******************************** Function Implementaion *******************************/
void ADC_Init(ADC_Vref_type vref, ADC_Prescaler_type prescaler)
{
	/* ADC Clock Adjustment */
	SELECT_PS(prescaler);
	
	/* ADC Voltage Reference Selection */
	SELECT_VREF(vref);
	switch(vref)
	{
		case VREF_AVCC:
			voltRef = 5000;
			break;
			
		case VREF_256:
			voltRef = 2560;
			break;
			
		case VREF_AREF:
			voltRef = AREF_VALUE;
			break;
			
		default:
			break;
	}
	
	/* Disable Adjusted Left Option */
	CLEAR_BIT(ADMUX, ADLAR);
	
	/* Disable Auto Triggering Option */
	CLEAR_BIT(ADCSRA, ADATE);
	
	/* ADC Enable */
	SET_BIT(ADCSRA, ADEN);
}

uint16 ADC_Read(ADC_Channel_type ch)
{
	uint16 adc;
	uint8 adcl, adch;
		
	/* Select ADC Channel */
	SELECT_CH(ch);
		
	/* Start Conversion Operation */
	SET_BIT(ADCSRA, ADSC);
		
	/* Wait Until Conversion is Done */
	while(READ_BIT(ADCSRA, ADSC)); // Max 25 cycle
		
	/* Read and Return ADC */
	adcl = ADCL;
	adch = ADCH;
	adc = ((uint16)adch << 8) | ((uint16)adcl);
		
	return adc;
}

uint16 ADC_ReadVolt(ADC_Channel_type ch)
{
	/* Voltage with respect to ADC voltage Reference (in mV) */
	uint16 volt = (ADC_Read(ch)*(uint32)voltRef)/1024;
	return volt;
}
