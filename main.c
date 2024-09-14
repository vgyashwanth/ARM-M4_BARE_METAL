/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include"NVIC.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


int main(void)
{	
	
	/*enabling the IRQ_0 i.e watch dog interrupt in stm32f411ceu6*/
	
	/*Step:1 setting the pending bit*/
	 NVIC_ISPR(0) |= (1U<<18); /* the interrupt is generated but present in pending state */

	/*enabling the interrupt*/
	  NVIC_ISER(0) |= (1U<<18);     /*Enable the interrupt check the interrupt in pending state*/

	for(;;);
  
}



