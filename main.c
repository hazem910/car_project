/*
 * main.c
 *
 * Created: 1/21/2020 1:40:33 PM
 *  Author: hazem
 */ 

#include "led.h"
#include "timers.h"
int main (void) {
	Led_Init(LED_3);
	while(1){
		Led_On(LED_3);
		timer2DelayMs(1000);
		Led_Off(LED_3);
timer2DelayMs(1000);
			
	}
	
return 0;	
	
}
