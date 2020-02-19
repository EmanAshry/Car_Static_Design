/*
 * STATIC_CAR.c
 *
 * Created: 2/19/2020 1:47:02 AM
 *  Author: Ema
 */ 


#include "car_sm.h"
#include "Timer.h"

int main(void)
{
	/*Timer_cfg_s Tim_cfg = {TIMER_CH0,T0_NORMAL_MODE,6,T0_POLLING};
	Timer_Init(&Tim_cfg);
	
	Timer_Start(TIMER_CH0,T0_MAX_VALUE);
	*/
	/*initialize the car control*/
	Car_SM_Init();
	
    while(1)
    {
		/*keep updating the car control with new data and giving different controls according to the input data*/
		Car_SM_Update();
    }
}