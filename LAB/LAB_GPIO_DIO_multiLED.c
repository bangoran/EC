/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : Junhyeok Bang
Created          : 05-03-2021
Modified         : 09-20-2024
Language/ver     : C++ in Keil uVision
/----------------------------------------------------------------*/

#include "ecRCC2.h"
#include "ecGPIO2.h"

#define LED0 PA_5
#define LED1 PA_6
#define LED2 PA_7
#define LED3 PB_6
#define BUTTON_PIN PC_13

// Initialiization 
void setup(void) {
	RCC_HSI_init();
	// initialize the pushbutt6on pin as an input:
	GPIO_init(BUTTON_PIN, INPUT);
	GPIO_pupd(BUTTON_PIN, PU);  
	// initialize the LED pin as an output:
	GPIO_init(LED0, OUTPUT);
	GPIO_otype(LED0,PUSH_PULL);
	GPIO_pupd(LED0, PU);
	GPIO_ospeed(LED0, MS);
	GPIO_init(LED1, OUTPUT);
	GPIO_otype(LED1,PUSH_PULL);
	GPIO_pupd(LED1, PU);
	GPIO_ospeed(LED1, MS);
	GPIO_init(LED2, OUTPUT);
	GPIO_otype(LED2,PUSH_PULL);
	GPIO_pupd(LED2, PU);
	GPIO_ospeed(LED2, MS);
	GPIO_init(LED3, OUTPUT);
	GPIO_otype(LED3,PUSH_PULL);
	GPIO_pupd(LED3, PU);
	GPIO_ospeed(LED3, MS);	
}
	
int main(void) { 
 	setup();
	int buttonState=0; // button state read
	int state=0; // save the button state (for debouncing)
	int count=0; // debouncing count-> delay
	
	int LED0_state =1; // first LED on
	int LED1_state =0; 
	int LED2_state =0;
	int LED3_state =0; // other LEDs off
	
	int i = 0; // LED counter
	
	
	
while(1){
		// check if the pushbutton is pressed. Turn LED on/off accordingly:
		buttonState = GPIO_read(BUTTON_PIN);
		if(buttonState == 0) {
			state=1; // check button input
		};
		
		if(count > 50000){
			if(state == 1)	{
				if (i==0){
				LED3_state=0;
				LED0_state=1; // each if & else if -> turn on & turn off LED 
				i++;//LED counter+1
				}
				else if (i==1){
				LED0_state=0;
				LED1_state=1;
				i++;
				}				
				else if (i==2){
				LED1_state=0;
				LED2_state=1;
				i++;
				}				
				else if (i==3){
				LED2_state=0;
				LED3_state=1;
				i=0; // LED couner reset
				} // LEDs turn on sequentially
				GPIO_write(LED0, LED0_state);
				GPIO_write(LED1, LED1_state);
				GPIO_write(LED2, LED2_state);
				GPIO_write(LED3, LED3_state); //set LED 
			}
			count=0;
			state=0;
		}
		else{
			GPIO_write(LED0, LED0_state);
			GPIO_write(LED1, LED1_state);
			GPIO_write(LED2, LED2_state);
			GPIO_write(LED3, LED3_state);// if count<50000 -> maintain the status
		}
		count++;
	}
}