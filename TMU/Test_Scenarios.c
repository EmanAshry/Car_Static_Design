/*
 * Test_Scenarios.c
 *
 * Created: 2/26/2020 8:47:50 PM
 *  Author: Ema
 */ 

#include "Test_Scenarios.h"

static DIO_Cfg_s LED1_cfg ={GPIOB,BIT1,OUTPUT};
static DIO_Cfg_s LED2_cfg ={GPIOB,BIT2,OUTPUT};
	
void Test_Scenarios(void)
{
	DIO_init(&LED1_cfg);
	DIO_init(&LED2_cfg);

	TMU_ConfigType TMU_cfg ={TIMER_CH0,1};
	/************************************************************************/
	/*						Tasks configuration                             */
	/************************************************************************/
	TMU_SW_Timer   TMU_task1_LED1={0,500,PERIODIC,Task_LED1};
	TMU_SW_Timer   TMU_task2_LED1={1,99,PERIODIC,Task_LED1};
	TMU_SW_Timer   TMU_task3_LED1={2,500,PERIODIC,Task_LED1};
	TMU_SW_Timer   TMU_task4_LED1={3,852,PERIODIC,Task_LED1};
	TMU_SW_Timer   TMU_task5_LED1={4,500,PERIODIC,Task_LED1};
	TMU_SW_Timer   TMU_task6_LED1={5,500,PERIODIC,Task_LED1};
	TMU_SW_Timer   TMU_task7_LED1={6,300,PERIODIC,Task_LED1};
	TMU_SW_Timer   TMU_task8_LED1={7,500,PERIODIC,Task_LED1};
	TMU_SW_Timer   TMU_task9_LED1={8,148,PERIODIC,Task_LED1};
	TMU_SW_Timer   TMU_task10_LED1={9,500,PERIODIC,Task_LED1};

	TMU_SW_Timer   TMU_task11_LED2={5,500,PERIODIC,Task_LED2};		//extra task
	TMU_SW_Timer   TMU_task1_No_Start={0,500,ONESHOOT,Task_LED1};	//task not started to test empty buffer


	TMU_Init(&TMU_cfg);
	/************************************************************************/
	/*					TEST Scenario 1: FULL_BUFFER                        */
	/************************************************************************/
	TMU_Start_Timer(&TMU_task1_LED1);
	TMU_Start_Timer(&TMU_task2_LED1);
	TMU_Start_Timer(&TMU_task3_LED1);
	TMU_Start_Timer(&TMU_task4_LED1);
	TMU_Start_Timer(&TMU_task5_LED1);
	TMU_Start_Timer(&TMU_task6_LED1);
	TMU_Start_Timer(&TMU_task7_LED1);
	TMU_Start_Timer(&TMU_task8_LED1);
	TMU_Start_Timer(&TMU_task9_LED1);
	TMU_Start_Timer(&TMU_task10_LED1);

	TMU_Start_Timer(&TMU_task11_LED2);		 //added task after FULL_BUFFER state will not work


	/************************************************************************/
	/*					TEST Scenario 2: EMPTY_BUFFER                       */
	/************************************************************************/
	TMU_Stop_Timer(&TMU_task1_No_Start);	//stop and delete a task from empty buffer


	/************************************************************************/
	/*					TEST Scenario 3: Random access                      */
	/************************************************************************/
	TMU_Stop_Timer(&TMU_task6_LED1);		//stop and delete a task from the full buffer
	TMU_Start_Timer(&TMU_task11_LED2);		//add another task

}

void Task_LED1(void)
{
	DIO_Toggle(GPIOB,BIT1);
}

void Task_LED2(void)
{
	DIO_Toggle(GPIOB,BIT2);
}