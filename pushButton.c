/*
 * pushButton.c
 *
 * Created: 1/17/2020 6:46:38 PM
 *  Author: hazem
 */ 
#include "pushButton.h"
/*implementation of pushbuttons initialization */
void pushButtonInit(En_buttonId_t en_butotn_id){
	
	switch(en_butotn_id){
		case BTN_0:
		          gpioPinDirection(BTN_0_GPIO,BTN_0_BIT,INPUT);
				  gpioPinWrite(BTN_0_GPIO,BTN_0_BIT,HIGH);
				  break;
		          
		case BTN_1:
		          gpioPinDirection(BTN_1_GPIO,BTN_1_BIT,INPUT);
				  gpioPinWrite(BTN_1_GPIO,BTN_1_BIT,HIGH);
				 
				  break;
		default:
		       break;		  
		
		
		
	}
}

/*implementation of push button get status */
En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id){
	           En_buttonStatus_t ret =Released; 
			   uint8_t data=0;        
			 	  switch(en_butotn_id){
				 	  case BTN_0:
				 	           
								data=gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
								break;
				 	  case BTN_1:
				 	           
				 	              data=gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
				 	              break;
				 	  default:
				 	           break;  
				 	  
			 	  }
				if(data==1){
				ret=Released;
				}
				else
			{
					ret=Pressed;
				}
				
					   
					
				  return ret;
}