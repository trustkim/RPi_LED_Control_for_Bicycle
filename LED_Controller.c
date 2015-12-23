#include "LED_Controller.h"

void blink(int PIN_NUM, int interval_ms, int count){
	int i;
	for(i=0;i<count;i++) {
		digitalWrite(PIN_NUM, HIGH);
		delay(interval_ms);
		digitalWrite(PIN_NUM, LOW);
		delay(interval_ms);
	}
}

void turnOn(int PIN_NUM) {
	digitalWrite(PIN_NUM, HIGH);
}
void turnOff(int PIN_NUM) {
	digitalWrite(PIN_NUM, LOW);
}