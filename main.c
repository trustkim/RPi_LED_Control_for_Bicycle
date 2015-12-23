#include <stdio.h>
#include "main.h"
#include "LED_Controller.c"
#include "switchListener.c"
#include "breakLED.c"
#include "signalLED.c"

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
