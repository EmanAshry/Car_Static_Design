/*
 * Steering.c
 *
 * Created: 2/18/2020 6:49:57 PM
 *  Author: Ema
 */ 

 #include "Steering.h"


 ERROR_STATUS Steering_Init(void)
 {
    ERROR_STATUS ERROR = E_OK;
	 
	 ERROR = Motor_Init(MOTOR_1);
	 ERROR = Motor_Init(MOTOR_2);

	 return ERROR;
 }

 ERROR_STATUS Steering_SteerCar(uint8_t Steering_CarCmd, uint8_t speed)
 {
    ERROR_STATUS ERROR = E_OK;
	
	 switch (Steering_CarCmd)
	 {
	    case CAR_STOP:
		 {
			 ERROR = Motor_Stop(MOTOR_1);
			 ERROR = Motor_Stop(MOTOR_2);
		 }
		 break;
		 case CAR_FORWARD:
		 {
			 ERROR = Motor_Direction(MOTOR_1,MOTOR_FORWARD);
			 ERROR = Motor_Direction(MOTOR_2,MOTOR_FORWARD);
			 ERROR = Motor_Start(MOTOR_1,speed);
			 ERROR = Motor_Start(MOTOR_2,speed);
		 }
		 break;
		 case CAR_BACKWARD:
		 {
			 ERROR = Motor_Direction(MOTOR_1,MOTOR_BACKWARD);
			 ERROR = Motor_Direction(MOTOR_2,MOTOR_BACKWARD);
			 ERROR = Motor_Start(MOTOR_1,speed);
			 ERROR = Motor_Start(MOTOR_2,speed);
		 }
		 break;
		 case CAR_RIGHT:
		 {
			 ERROR = Motor_Direction(MOTOR_1,MOTOR_FORWARD);
			 ERROR = Motor_Direction(MOTOR_2,MOTOR_BACKWARD);
			 ERROR = Motor_Start(MOTOR_1,speed);
			 ERROR = Motor_Start(MOTOR_2,speed);
		 }
		 break;
		 case CAR_LEFT:
		 {
			 ERROR = Motor_Direction(MOTOR_1,MOTOR_BACKWARD);
			 ERROR = Motor_Direction(MOTOR_2,MOTOR_FORWARD);
			 ERROR = Motor_Start(MOTOR_1,speed);
			 ERROR = Motor_Start(MOTOR_2,speed);
		 }
		 break;
		 default:
		 ERROR = E_NOK;
		 break;
	 }

	 return ERROR;
 }