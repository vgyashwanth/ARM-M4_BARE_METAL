#ifndef __NVIC__
#define __NVIC__
#include<stdint.h>

#define NVIC_ISER(n)  (*(volatile uint32_t *)(0xE000E100 + 4*n )) /*Interrupt enable register*/
#define NVIC_ICER(n)  (*(volatile uint32_t *)(0XE000E180 + 4*n )) /*Interrupt clear register*/
#define NVIC_ISPR(n)  (*(volatile uint32_t *)(0XE000E200 + 4*n )) /*Interrupt pending register*/
#define NVIC_ICPR(n)  (*(volatile uint32_t *)(0XE000E280 + 4*n )) /*Interrupt clear register*/
#define NVIC_IABR(n)  (*(volatile uint32_t *)(0xE000E300 + 4*n )) /*Interrupt Active register*/
#define NVIC_IPR(n)   (*(volatile uint32_t *)(0xE000E400+ 4*n ))  /*Interrupt priority register*/

#endif
