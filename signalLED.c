// #define BT_STATE_OFF 0  // LOW -> LOW
// #define BT_STATE_UP 1   // LOW -> HIGH
// #define BT_STATE_ON 2   // HIGH -> HIGH
// #define BT_STATE_DOWN 3 // HIGH -> LOW
#define LEFT_SIG 1
#define RIGHT_SIG 2
#define LED_STATE_OFF 0
#define LED_STATE_ON 1

// int btState=0;
int sigState=0;
int left_LED_State=LED_STATE_OFF;
int right_LED_State=LED_STATE_OFF;

int checkButtonState() {
  return BT_STATE_OFF;
}
// int checkSignalState() {
//   return LEFT_SIG;
// }

void runSignalLED() {
  switch(signalState) {
    case LEFT_SIG: {
      if(left_LED_State==LED_STATE_ON) {
        turnOff(YELLOW_LEFT);
        left_LED_State=LED_STATE_OFF;
      } else {
        turnOn(YELLOW_LEFT);
        left_LED_State=LED_STATE_ON;
      }
      break;
    } case RIGHT_SIG: {
      if(right_LED_State==LED_STATE_ON) {
        turnOff(YELLOW_RIGHT);
        right_LED_State=LED_STATE_OFF;
      } else {
        turnOn(YELLOW_RIGHT);
        right_LED_State=LED_STATE_ON;
      }
      break;
    }
  }
}
