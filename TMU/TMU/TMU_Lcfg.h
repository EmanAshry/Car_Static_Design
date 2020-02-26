/*
 * TMU_Lcfg.h
 *
 * Created: 2/25/2020 5:55:32 PM
 *  Author: Ema
 */ 


#ifndef TMU_LCFG_H_
#define TMU_LCFG_H_

/************************************************************************/
/*				 INCLUDES											    */
/************************************************************************/
#include "std_types.h"

/************************************************************************/
/*				 DEFINES											    */
/************************************************************************/

typedef struct TMU_ConfigType{
	uint8_t Timer_CH;
	uint8_t resloution;
	
}TMU_ConfigType;

TMU_ConfigType guTMU_cfg;

extern TMU_ConfigType guTMU_cfg;

#endif /* TMU_LCFG_H_ */