/*
 * PWM.c
 *
 * Created: 2/17/2020 11:20:24 AM
 *  Author: Ema
 */ 

#include "PWM.h"

ERROR_STATUS Pwm_Init(Pwm_Cfg_s *Pwm_Cfg)
{
	ERROR_STATUS ERROR = E_OK;
	
	switch(Pwm_Cfg->Channel)
	{
		case PWM_CH0:
		ERROR = E_NOK;
		break;
		case PWM_CH1A:
		{
			DIO_Cfg_s DIO_cfg_B4 = {GPIOD,BIT4,OUTPUT};
			
			CLEAR_BIT(TCNT1,0xFFFF);
			CLEAR_BIT(ICR1,0xFFFF);
			CLEAR_BIT(OCR1A,0xFF);
			
			SET_BIT(TCNT1,0x0000);
			SET_BIT(TCCR1,(0x0218|0x8000));
			SET_BIT(OCR1A,0x0000);
			SET_BIT(ICR1,0x00FF);
			SET_BIT(TIMSK,0);
				
			ERROR = DIO_init(&DIO_cfg_B4);		
		
		}
		break;
		case PWM_CH1B:
		{
			DIO_Cfg_s DIO_cfg_B5 = {GPIOD,BIT5,OUTPUT};
				
			CLEAR_BIT(TCNT1,0xFFFF);
			CLEAR_BIT(OCR1B,0xFF);
			
			SET_BIT(TCNT1,0x0000);
			SET_BIT(TCCR1,(0x0218|0x2000));
			SET_BIT(OCR1B,0x0000);
			SET_BIT(ICR1,0x00FF);
			SET_BIT(TIMSK,0);
					
			ERROR = DIO_init(&DIO_cfg_B5);
			
		}
		break;
		case PWM_CH2:
		ERROR = E_NOK;
		break;
		default:
		ERROR = E_NOK;
	}
			
	return ERROR;	
}

ERROR_STATUS Pwm_Start(uint8_t Channel,uint8_t Duty,uint32_t Frequncy)
{
	ERROR_STATUS ERROR = E_OK;
	uint8_t OCR_TOP_Value = 0;
	
	PWM_Status = PWM_STARTED;
	OCR_TOP_Value = (Duty*255)/100;
	
	switch(Channel)
	{
		case PWM_CH0:
		ERROR = E_NOK;
		break;
		case PWM_CH1A:
		SET_BIT(OCR1A,OCR_TOP_Value);
		SET_BIT(TCCR1,0x0003);
		break;
		case PWM_CH1B:
		SET_BIT(OCR1B,OCR_TOP_Value);
		SET_BIT(TCCR1,0x0003);
		break;
		case PWM_CH2:
		ERROR = E_NOK;
		break;
	}
	
	return ERROR;
}

ERROR_STATUS Pwm_Update(uint8_t Channel,uint8_t Duty,uint32_t Frequncy)
{
	ERROR_STATUS ERROR = E_OK;
	uint8_t OCR_TOP_Value = 0;
	
	OCR_TOP_Value = (Duty*255)/100;
	
	if(PWM_Status==PWM_STARTED)
	{
		switch(Channel)
		{
			case PWM_CH0:
			ERROR = E_NOK;
			break;
			case PWM_CH1A:
			SET_BIT(OCR1A,OCR_TOP_Value);
			SET_BIT(TCCR1,0x0003);
			break;
			case PWM_CH1B:
			SET_BIT(OCR1B,OCR_TOP_Value);
			SET_BIT(TCCR1,0x0003);
			break;
			case PWM_CH2:
			ERROR = E_NOK;
			break;
		}
	}
	else
	{
		ERROR = E_NOK;
	}
	
	return ERROR;
}

ERROR_STATUS Pwm_Stop(uint8_t Channel)
{
	ERROR_STATUS ERROR = E_OK;
	
	switch(Channel)
	{
		case PWM_CH0:
		ERROR = E_NOK;
		break;
		case PWM_CH1A:
		CLEAR_BIT(TCCR1B,0x07);
		PWM_Status = PWM_STOPED;
		break;
		case PWM_CH1B:
		CLEAR_BIT(TCCR1B,0x07);
		PWM_Status = PWM_STOPED;
		break;
		case PWM_CH2:
		Timer_Stop(TIMER_CH2);
		break;
		default:
		ERROR = E_NOK;
		break;
	}
	
	return ERROR;
}