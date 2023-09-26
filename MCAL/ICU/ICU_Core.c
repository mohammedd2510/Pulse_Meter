 /**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  ICU_Core.c 
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "ICU_Core.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
volatile uint8 ICU_Cnt=0;
volatile uint32 Cap2 =0;
volatile uint32 Cap1 =0;
volatile uint32 Cap3 =0;


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

uint32 Timer1_TickTime_us;
/******************************************************************************
* \Syntax          : void ICU_Init(void)     
* \Description     : Initializes The ICU Module                                                                              
* \Parameters      : Void                                                                          
* \Return value:   : Void                                
*******************************************************************************/
void ICU_Init(void){
	GPT_Init();
	SET_ICU_RISING_EDGE();
	SET_ICU_INTERRUPT_ENABLE();
	Timer1_TickTime_us = ((Timer1_Prescaler_value)/(F_CPU/1000000));
}
/******************************************************************************
* \Syntax          : uint32 ICU_CaptureTime(void)
* \Description     : Capture The On Time of any pulse and returns it
* \Parameters      : Void
* \Return value:   : Return  ON_Time
*******************************************************************************/
uint32 ICU_CaptureOnTime(void){
	uint32 ON_Time =0;
	if (ICU_Cnt == 2)
	{
		ON_Time = (Cap2 - Cap1) * Timer1_TickTime_us;
		ICU_Cnt =0;
		SET_ICU_INTERRUPT_ENABLE();
	}
	return ON_Time;
}

/**********************************************************************************************************************
 *  END OF FILE: ICU_Core.c 
 *********************************************************************************************************************/