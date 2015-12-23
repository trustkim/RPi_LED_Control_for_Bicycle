#include <stdio.h>
#include "main.h"
#include "LED_Controller.c"
#include "switchListener.c"
#include "breakLED.c"
#include "signalLED.c"

/*
void breakOn(){
	digitalWrite(REDBREAK,1);
}
void breakOff(){
	status=0;
}
void leftOn(){
//	if(status=LEFT){
		for(;;){
		digitalWrite(YELLOWLEFT,1);
		delay(100);
		digitalWrite(YELLOWLEFT,0);
		delay(100);
		}
//	}
}
void rightOn(){
//	if(status=RIGHT){
		for(;;){
		digitalWrite(YELLOWRIGHT,1);
		delay(100);
		digitalWrite(YELLOWRIGHT,0);
		delay(100);
		}
//	}
}
void yellowOff(){

//	status=0;
}
*/

void printfoobar() {
	printf("foobar");
	delay(1000);
}

int main(void){
	if(wiringPiSetup()==-1)
		return 1;

	callAllPinModes();
	ceremony();

	while(1) {
		// mabe need some Listner to set of switch
		updateButtonState();
		runBreakLED();
		runSignalLED();
	}

	return 0;
}

void callAllPinModes() {
	pinMode(YELLOW_LEFT ,OUTPUT);
	pinMode(YELLOW_RIGHT,OUTPUT);
	pinMode(RED_BREAK,OUTPUT);

	turnOff(RED_BREAK);
	turnOff(YELLOW_LEFT);
	turnOff(YELLOW_RIGHT);
}
