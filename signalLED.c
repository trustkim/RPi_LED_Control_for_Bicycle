// #define BT_STATE_OFF 0  // LOW -> LOW
// #define BT_STATE_UP 1   // LOW -> HIGH
// #define BT_STATE_ON 2   // HIGH -> HIGH
// #define BT_STATE_DOWN 3 // HIGH -> LOW

// int btState=0;
// int signalState=0;
int left_LED_State=LED_STATE_OFF;
int right_LED_State=LED_STATE_OFF;

// int checkSignalState() {
//   return LEFT_SIG;
// }

void runSignalLED() {
  if(leftSignalState==SIG_ON) {
    if(left_LED_State==LED_STATE_ON) {
      turnOff(YELLOW_LEFT);
      left_LED_State=LED_STATE_OFF;
    } else {
      turnOn(YELLOW_LEFT);
      left_LED_State=LED_STATE_ON;
    }
  } else {
    turnOff(YELLOW_LEFT);
    left_LED_State = LED_STATE_OFF;
  }

  if(rightSignalState==SIG_ON) {
    if(right_LED_State==LED_STATE_ON) {
      turnOff(YELLOW_RIGHT);
      right_LED_State=LED_STATE_OFF;
    } else {
      turnOn(YELLOW_RIGHT);
      right_LED_State=LED_STATE_ON;
    }
  } else {
    turnOff(YELLOW_RIGHT);
    right_LED_State = LED_STATE_OFF;
  }

  delay(100);
}
