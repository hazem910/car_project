/*
 * SwICU.h
 *
 *  Created on: Oct 27, 2019
 *      Author: Sprints
 */

#ifndef SWICU_H_
#define SWICU_H_

#include "interrupt.h"
#include "timers.h"
#include "gpio.h"

typedef enum EN_SwICU_Edge_t{
	SwICU_EdgeFalling = 0x00,
	SwICU_EdgeRisiging = 0x40
}EN_SwICU_Edge_t;

void SwICU_Init(EN_SwICU_Edge_t a_en_inputCaptureEdge);
EN_SwICU_Edge_t SwICU_GetCfgEdge(void);
void SwICU_SetCfgEdge(EN_SwICU_Edge_t a_en_inputCaptureEdge);
void SwICU_Read(volatile uint8_t * a_pu8_capt);
void SwICU_Stop(void);
void SwICU_Start(void);
void SwICU_Enable(void);
void SwICU_Disable(void);

#endif /* SWICU_H_ */
