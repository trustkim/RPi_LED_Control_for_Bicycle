#define BT_STATE_OFF 0  // LOW -> LOW
#define BT_STATE_UP 1   // LOW -> HIGH
#define BT_STATE_ON 2   // HIGH -> HIGH
#define BT_STATE_DOWN 3 // HIGH -> LOW

/* for signalLED.c */
#define SIG_OFF 0
#define SIG_ON 1
#define LED_STATE_OFF 0
#define LED_STATE_ON 1

int btBreakState = BT_STATE_OFF;
int btLeftState = BT_STATE_OFF;
int btRightState = BT_STATE_OFF;

int leftSignalState=SIG_OFF;
int rightSignalState=SIG_OFF;

// int debouncedReadButton(int PIN_NUM) {
//   return digitalRead(PIN_NUM);
// }

// check all button's state using debouncedReadButton
int checkButtonState(int PIN_NUM) {
  return digitalRead(PIN_NUM);
}

void updateButtonState() {
  btBreakState = checkButtonState(SW_BREAK);
  btLeftState = checkButtonState(SW_LEFT);
  btRightState = checkButtonState(SW_RIGHT);
}

void updagteSignal() {
  if(btLeftState==BT_STATE_ON)
    leftSignalState = SIG_ON;
  else leftSignalState = SIG_OFF;

  if(btRightState==BT_STATE_ON)
    rightSignalState = SIG_ON;
  else rightSignalState = SIG_OFF;
}
