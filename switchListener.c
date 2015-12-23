/* for debouncedBtnRead */
#define BREAK 0
#define LEFT 1
#define RIGHT 2

/* for signal control, they needs check by four ways */
#define BT_STATE_OFF 0  // LOW -> LOW
#define BT_STATE_UP 1   // LOW -> HIGH
#define BT_STATE_ON 2   // HIGH -> HIGH
#define BT_STATE_DOWN 3 // HIGH -> LOW

/* for signalLED.c */
#define SIG_OFF 0
#define SIG_ON 1
#define LED_STATE_OFF 0
#define LED_STATE_ON 1

/* for debouncedBtnRead */
int btnVolts[3] = {LOW,LOW,LOW};
int lastBtnState[3] = {LOW,LOW,LOW};
int curBtnState[3] = {LOW,LOW,LOW};
long lastDebounceTime_ms[3] = {0,0,0};
long debounceDelay = 50;

// int btBreakState = BT_STATE_OFF;
// int btLeftState = BT_STATE_OFF;
// int btRightState = BT_STATE_OFF;

int leftSignalState=SIG_OFF;
int rightSignalState=SIG_OFF;

void debouncedBtnRead(const int switch_index) {
  btnVolts[switch_index] = digitalRead(swPinIndexes[switch_index]);

  if(btnVolts[switch_index] != lastBtnState[switch_index]) {
    lastDebounceTime_ms[switch_index] = millis();
  }

  if((millis() - lastDebounceTime_ms[switch_index]) > debounceDelay) {
    if(btnVolts[switch_index] != curBtnState[switch_index]) {
      curBtnState[switch_index] = btnVolts[switch_index];
    }
  }

  lastBtnState[switch_index] = btnVolts[switch_index];
}

// check all button's state using debouncedBtnRead
int checkButtonState(int PIN_NUM) {
  return digitalRead(PIN_NUM);
}

void updateButtonState() {
  int i;
  for(i=0;i<3;i++) {
    debouncedBtnRead(i);
  }
  // btBreakState = checkButtonState(SW_BREAK);
  // btLeftState = checkButtonState(SW_LEFT);
  // btRightState = checkButtonState(SW_RIGHT);
}

void updagteSignal() {
  // TODO fix logical error
  if(curBtnState[LEFT]==BT_STATE_ON)
    leftSignalState = SIG_ON;
  else leftSignalState = SIG_OFF;

  if(curBtnState[RIGHT]==BT_STATE_ON)
    rightSignalState = SIG_ON;
  else rightSignalState = SIG_OFF;
}
