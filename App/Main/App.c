/*
 * App.c
 *
 * Created: 9/25/2023 3:34:43 PM
 * Author : Mohamed Osama
 */ 

#include "App.h"	

int main(void)
{
	PORT_Init(); // Initialize Pins Direction to be Output/Input
	Pulse_Meter_Init(); // Initialize Pulse Meter Application
	/****** Test The Pulse Meter Using PWM of Timer0 with Frequency = 244Hz and Duty Cycle = 10 %  ***************/ 
	PWM_Init();
	PWM0_Generate(10);
	/************************************************************************************************/
    while (1) 
    {
		Pulse_Meter_Start(); // Start The Pulse Meter Application
	}
}

