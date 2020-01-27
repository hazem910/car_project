/*
 * main1motor.c
 *
 * Created: 1/26/2020 2:23:32 PM
 *  Author: hazem
 */ 



#include "registers.h"
#include "gpio.h"
#include "softwareDelay.h"
#include "timers.h"
#include "interrupt.h"
#include "dcMotor.h"

extern uint16_t initialValue;
extern uint16_t ocr;

uint8_t gu8_speed = 1;
uint16_t gu16_counter = 0;

int main(void){

	timer1Init(T1_NORMAL_MODE, T1_OC1_DIS, T1_PRESCALER_NO, 0, 0, 0, 0, (T1_INTERRUPT_NORMAL | T1_INTERRUPT_CMP_1A));
	timer1Start();
	sei();

MotorDC_Init(MOT_1);
MotorDC_Init(MOT_2);
MotorDC_Dir(MOT_1, FORWARD);
MotorDC_Dir(MOT_2, FORWARD);


	for(gu8_speed=1;gu8_speed<99;gu8_speed++){
		gu16_counter = 0;
		while(gu16_counter < 340){
			gu16_counter++;
			MotorDC_Speed_PollingWithT0(gu8_speed);
			
		}
	}
	timer0DelayMs(2000);

	for(gu8_speed=99;gu8_speed>1;gu8_speed--){
		gu16_counter = 0;
		while(gu16_counter < 340){
			gu16_counter++;
			MotorDC_Speed_PollingWithT0(gu8_speed);
			
			 // PWM @ 1 KHz with variable speed
		}
	}
timer1Stop();
	MotorDC_Dir(MOT_1, STOP);
	MotorDC_Dir(MOT_2, STOP);
	timer0DelayMs(1000);
	MotorDC_Dir(MOT_1, FORWARD);
	MotorDC_Dir(MOT_2,STOP);
	gpioPinWrite(GPIOD,BIT4,HIGH);
	timer0DelayMs(140);
	

	while(gu16_counter < 1300){
		gu16_counter++;
		timer1SwPWM(50, 1); // PWM @ 1 KHz with variable speed
	}
	
	MotorDC_Dir(MOT_1, STOP);
	MotorDC_Dir(MOT_2, STOP);
	


	while(1){
		//timer1SwPWM(30, 1); // PWM @ 1 KHz with variable speed
	}
	return 0;
}


ISR(TIMER1_OVF_vect){
	gpioPinWrite(GPIOD, (BIT4 | BIT5), HIGH);
	TCNT1 = initialValue;
}

ISR(TIMER1_COMPA_vect){
	gpioPinWrite(GPIOD, (BIT4 | BIT5), LOW);
	OCR1A = ocr;
}