/*
 * car_sm.c
 *
 * Created: 2/18/2020 7:37:43 PM
 *  Author: Ema
 */ 

 #include "car_sm.h"

 ERROR_STATUS Car_SM_Init(void)
 {
	 ERROR_STATUS ERROR = E_OK;
	 
	 ERROR = Us_Init();									//initialize the ultrasonic
	 ERROR = Steering_Init();							//initialize the steering
	 ERROR = Steering_SteerCar(CAR_FORWARD,30);			//make the car move forward with speed 30% (30% duty cycle)

	 return ERROR;
 }


 ERROR_STATUS Car_SM_Update(void)
 {
	 ERROR_STATUS ERROR = E_OK;
	 
	 uint16_t Distance = 0;
	 uint8_t State = 0;
	
	/*fire the ultrasonic trigger to start it*/
	 Us_Trigger();
	
	/*read the distance*/
	 Us_GetDistance(&Distance);
	 DIO_Write(GPIOB,UPPER_NIBBLE,(Distance<<4));
	 _delay_ms(25);
	 
	/*if(Distance>30)
	{
		Steering_SteerCar(CAR_FORWARD,30);
	}
	if(Distance<30)
	{
		Steering_SteerCar(CAR_STOP,30);
	}*/
	/*decide and set the state according to the read distance*/
	 if ((Distance>=25) && (Distance<=30))
		{
			State = TURN_RIGHT;
		}
	 else 
	 if (Distance >30)
		{
			State = GO_FORWARD;
		}
	 else 
	 if (Distance < 25)
		{
			State = GO_BACK;
		}
	 
	 /*switch between the states to control the car to avoid obstacles*/
	 switch (State)
	 {
	    case TURN_RIGHT:
		 ERROR = Steering_SteerCar(CAR_RIGHT,50);
		 _delay_ms(300);
		 break;
		 case GO_FORWARD:
		 ERROR = Steering_SteerCar(CAR_FORWARD,30);
		 break;
		 case GO_BACK:
		 ERROR = Steering_SteerCar(CAR_BACKWARD,30);
		 break;
		 default:
		 ERROR = E_NOK;
		 break;
	 }

	 return ERROR;
 }