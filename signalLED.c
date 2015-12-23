
int LED_States[2] = {LED_STATE_OFF, LED_STATE_OFF};
// int left_LED_State=LED_STATE_OFF;
// int right_LED_State=LED_STATE_OFF;

void runSignalLED() {
  int i;
  for(i=1;i<3;i++) {
    if(signalStates[index]==SIG_ON) {
      if(LED_States[i-1]==LED_STATE_ON) {
        turnOff(swPinIndexes[i]);
        LED_States[i-1]=LED_STATE_OFF;
      } else {
        turnOn(swPinIndexes[i]);
        LED_States[i-1]=LED_STATE_ON;
      }
    } else {
      turnOff(swPinIndexes[i]);
      LED_States[i-1] = LED_STATE_OFF;
    }
  }
  // 
  //
  // if(signalStates[index]==SIG_ON) {
  //   if(right_LED_State==LED_STATE_ON) {
  //     turnOff(YELLOW_RIGHT);
  //     right_LED_State=LED_STATE_OFF;
  //   } else {
  //     turnOn(YELLOW_RIGHT);
  //     right_LED_State=LED_STATE_ON;
  //   }
  // } else {
  //   turnOff(YELLOW_RIGHT);
  //   right_LED_State = LED_STATE_OFF;
  // }

  delay(100);
}
