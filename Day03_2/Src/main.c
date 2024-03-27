/*
 * main.c
 *
 *  Created on: Mar 27, 2024
 *      Author: gorakh
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "led.h"
#include "switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	SwitchInit(SWITCH);
	LedInit(LED_GREEN);
	LedInit(LED_ORANGE);
	LedInit(LED_RED);
	LedInit(LED_BLUE);

	while(1) {
		while(SwitchGetState(SWITCH) == 0)
		{
		LedBlink(LED_GREEN ,200);
		LedBlink(LED_ORANGE, 200);
		LedBlink(LED_RED, 200);
		LedBlink(LED_BLUE, 200);
	}
		if(SwitchGetState(SWITCH) == 1)
			while(1){
				LedBlink(LED_BLUE ,200);
					LedBlink(LED_RED, 200);
					LedBlink(LED_ORANGE, 200);
					LedBlink(LED_GREEN, 200);
			}
	}
	return 0;
}

