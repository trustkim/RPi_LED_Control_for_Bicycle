const int LED_indexes[2] = {YELLOW_LEFT, YELLOW_RIGHT};
int LED_States[2] = {LOW, LOW};

void runSignalLED() {
  int i;
  for(i=1;i<3;i++) {
    if(curBtnState[i]==HIGH) {
      if(LED_States[i-1]==HIGH) {
        turnOff(LED_indexes[i-1]);
        LED_States[i-1]=LOW;
      } else {
        turnOn(LED_indexes[i-1]);
        LED_States[i-1]=HIGH;
      }
    } else {
      turnOff(LED_indexes[i-1]);
      LED_States[i-1] = LOW;
    }
  }

  delay(100);
}
