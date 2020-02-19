/*
 * timers.h
 *
 *  Created on: Oct 22, 2019
 *      Author: Sprints
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "registers.h"
#include "std_types.h"
#include "Common_Macros.h"

#define  Timer_0      0
#define  Timer_1      1
#define  Timer_2      2

#define  COUNTER_MODE 0
#define  TIMER_MODE   1

#define  TIMER_MODE_POLLING   0
#define  TIMER_MODE_INTERRUPT 1

 #define  PRESCALER_1          1
 #define  PRESCALER_8          2
 #define  PRESCALER_32         3
 #define  PRESCALER_64         4
 #define  PRESCALER_128        5
 #define  PRESCALER_256        6
 #define  PRESCALER_1024       7

typedef struct Timer_Cfg_ST{
   uint8_t Timer_Ch;
	uint8_t Timer_Mode;
	uint8_t Timer_PreScaler;
	uint8_t Timer_Interrupt_Mode;
}Timer_Cfg_ST;

extern uint8_t Timer_Init (Timer_Cfg_ST *Timer_Info);
extern uint8_t Timer_Start (uint8_t Timer_Chan, uint16_t Timer_Count_No);
extern uint8_t Timer_Stop (uint8_t Timer_Chan);
extern uint8_t Timer_Get_Value (uint8_t Timer_Chan, uint16_t *Timer_Value);
extern uint8_t Timer_Set_Value (uint8_t Timer_Chan, uint16_t Timer_Value);
extern uint8_t Timer_Get_Status (uint8_t Timer_Chan, uint8_t *Timer_Status);

#endif /* TIMERS_H_ */