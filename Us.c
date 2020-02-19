/*
 * Us.c
 *
 * Created: 2/18/2020 12:39:51 AM
 *  Author: Ema
 */ 

 #include "Us.h"

 ERROR_STATUS Us_Init(void)
 {
    ERROR_STATUS ERROR = E_OK;
	 
	 DIO_Cfg_s dio_cfg_Triger = {GPIOB,BIT1,HIGH};
	 Icu_cfg_s Icu_cfg ={ICU_CH2,ICU_TIMER_CH0};
	 
	 ERROR = Icu_Init(&Icu_cfg); 
	 ERROR = DIO_init(&dio_cfg_Triger);

	 return ERROR;
 }


 ERROR_STATUS Us_Trigger(void)
 {
    ERROR_STATUS ERROR = E_OK;
	 
	 DIO_Write(GPIOB,BIT1,HIGH);				//trigger the sensor
	 _delay_us(5);
	 
	 DIO_Write(GPIOB,BIT1,0);
	 _delay_us(5);

	 return ERROR;
 }


 ERROR_STATUS Us_GetDistance(uint16_t *Distance)
 {
	 ERROR_STATUS ERROR = E_OK;
	 uint32_t ICU_read = 0;
	 
    Icu_ReadTime(ICU_CH2,ICU_RISE_TO_FALL,&ICU_read);
    *Distance = ((ICU_read*16)/58);						//Distance in cm
    
	 return ERROR;
 }
