/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : Junhyeok Bang
Created          : 05-03-2021
Modified         : 09-20-2024
Language/ver     : C++ in Keil uVision
/----------------------------------------------------------------*/

#include "ecRCC2.h"
#include "ecGPIO2.h"

#define LED_PIN PA_5
#define BUTTON_PIN PC_13

// Initialiization 
void setup(void) {
	RCC_HSI_init();
	// initialize the pushbutt6on pin as an input:
	GPIO_init(BUTTON_PIN, INPUT);
	GPIO_pupd(BUTTON_PIN, PU);  
	// initialize the LED pin as an output:
	GPIO_init(LED_PIN, OUTPUT);
	GPIO_otype(LED_PIN,PUSH_PULL);
	GPIO_ospeed(LED_PIN,MS);
}
	
int main(void) { 
 	setup();
	int buttonState=0; // button state
	int LED_state=0;
	int state=0; //save the button state (for debouncing)
	int count=0; //debouncing count-> delay
	
	while(1){
		// check if the pushbutton is pressed. Turn LED on/off accordingly:
		buttonState = GPIO_read(BUTTON_PIN);
		if(buttonState == 0) state=1; // debouncing button state check
		
		if(count > 100000){
			if(state == 1)	{
				LED_state = ~LED_state;
				GPIO_write(LED_PIN, LED_state);
			}
			count=0;
			state=0;
		}
		else{
			GPIO_write(LED_PIN, LED_state); // LED change decision time (count = 100000) less than 100000 -> keep current state
		}
		count++;
	}
}