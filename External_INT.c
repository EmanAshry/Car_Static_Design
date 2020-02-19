/*
 * External_INT.c
 *
 * Created: 2/18/2020 12:40:58 PM
 *  Author: Ema
 */ 

#include "External_INT.h"

void External_INT_Init(uint8_t INT_CH,uint8_t EDGE)
{
	SET_BIT(SREG,(1<<7));								 // Enable interrupts by setting I-bit

	switch(INT_CH)
	{
		case EXTERNAL_INT_CH0:
		break;
		case EXTERNAL_INT_CH1:
		break;
		case EXTERNAL_INT_CH2:
		{
			DIO_Cfg_s DIO_cfg_PB2 = {GPIOB,BIT2,INPUT};
			DIO_init(&DIO_cfg_PB2);
			DIO_Write(GPIOB,BIT2,HIGH);
			
			switch(EDGE)
			{
				case EdgeRisiging:
				SET_BIT(MCUCSR,(1<<6));			         // Trigger INT2 with the raising edge
				break;

				case EdgeFalling:
				CLEAR_BIT(MCUCSR,(1<<6));				 // Trigger INT2 with the falling edge
				break;
				
				default:
				break;
			}
		}
		break;
		default:
		break;
	}

}


void External_INT_Enable(uint8_t INT_CH,uint8_t EDGE)
{
	switch(INT_CH)
	{
		case EXTERNAL_INT_CH0:
		break;
		case EXTERNAL_INT_CH1:
		break;
		case EXTERNAL_INT_CH2:
		{
			switch(EDGE)
			{
				case EdgeRisiging:
				SET_BIT(GICR,(1<<5));					 // Enable external interrupt pin INT2
				SET_BIT(MCUCSR,(1<<6));			         // Trigger INT2 with the raising edge
				break;

				case EdgeFalling:
				SET_BIT(GICR,(1<<5));					 // Enable external interrupt pin INT2
				CLEAR_BIT(MCUCSR,(1<<6));				 // Trigger INT2 with the falling edge
				break;
				
				default:
				break;
			}
		}
		break;
		default:
		break;
	}

}