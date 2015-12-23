void blink(int PIN_NUM, int interval_ms, int count);
void turnOn(int PIN_NUM);
void turnOff(int PIN_NUM);
void ceremony();

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

/* */
void ceremony(){
	turnOn(YELLOW_LEFT);
	delay(500);
	turnOn(RED_BREAK);
	delay(500);
	turnOn(YELLOW_RIGHT);
	delay(500);
	turnOff(RED_BREAK);
	turnOff(YELLOW_LEFT);
	turnOff(YELLOW_RIGHT);
	delay(1000);
	turnOn(RED_BREAK);
	turnOn(YELLOW_LEFT);
	turnOn(YELLOW_RIGHT);
	delay(250);
	turnOff(RED_BREAK);
	turnOff(YELLOW_LEFT);
	turnOff(YELLOW_RIGHT);
	delay(250);
	turnOn(RED_BREAK);
	turnOn(YELLOW_LEFT);
	turnOn(YELLOW_RIGHT);
	delay(250);
	turnOff(RED_BREAK);
	turnOff(YELLOW_LEFT);
	turnOff(YELLOW_RIGHT);
}
