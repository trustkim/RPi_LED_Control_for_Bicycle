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

/* for signalLED.c */
int signalStates[2] = {SIG_OFF, SIG_OFF};
// int leftSignalState = SIG_OFF;
// int rightSignalState = SIG_OFF;

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
void updateButtonState() {
  int i;
  for(i=0;i<3;i++) {
    debouncedBtnRead(i);
  }
}

int checkSignalState(int switch_index) {
  if(lastBtnState[switch_index]==LOW && curBtnState[switch_index]==LOW)
    return BT_STATE_OFF;
  else if(lastBtnState[switch_index]==LOW && curBtnState[switch_index]==HIGH)
    return BT_STATE_UP;
  else if(lastBtnState[switch_index]==HIGH && curBtnState[switch_index]==HIGH)
      return BT_STATE_ON;
  else if(lastBtnState[switch_index]==HIGH && curBtnState[switch_index]==LOW)
    return BT_STATE_DOWN;
  else return -1;
}
void updagteSignal() {
  int i;
  for (i=1;i<3;i++) { // check without RED_LED
    if(checkSignalState(i) == BT_STATE_ON)
      signalStates[i-1] = SIG_ON;
    else signalStates[i-1] = SIG_OFF;
  }
}
