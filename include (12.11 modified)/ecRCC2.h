/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : Junhyeok Bang
Created          : 05-03-2021
Modified         : 09-20-2024
Language/ver     : C++ in Keil uVision
/----------------------------------------------------------------*/

#ifndef __EC_RCC2_H
#define __EC_RCC2_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

//#include "stm32f411xe.h"

void RCC_HSI_init(void);
void RCC_PLL_init(void);
void RCC_GPIOA_enable(void);
void RCC_GPIOB_enable(void);
void RCC_GPIOC_enable(void);
void RCC_GPIOD_enable(void);
void RCC_GPIOE_enable(void);
void RCC_GPIOF_enable(void);
void RCC_GPIOG_enable(void);
void RCC_GPIOH_enable(void);
// void RCC_GPIO_enable(GPIO_TypeDef * GPIOx);


extern int EC_SYSCL;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __EC_RCC2_H
