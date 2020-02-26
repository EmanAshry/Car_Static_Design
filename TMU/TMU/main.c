/*
 * main.c
 *
 * Created: 2/24/2020 7:08:01 PM
 *  Author: Ema
 */ 

#include "Test_Scenarios.h"
#include "TMU.h"


int main(void)
{
	
	Test_Scenarios();
	
	while(1)
	{
		TMU_Dispatch();
		
	}
}

