/**
  * @file switchListener.c
  * @author TK (trustkim@pukyong.ac.kr), lastman (junho5656@naver.com)
  * @version v1.0
  */

/* for debouncedBtnRead */
#define BREAK 0

/* for debouncedBtnRead */
int btnVolts[3] = {LOW,LOW,LOW};
int lastBtnState[3] = {LOW,LOW,LOW};
int curBtnState[3] = {LOW,LOW,LOW};
int debouncedLastBtnState[3] = {LOW, LOW, LOW};
long lastDebounceTime_ms[3] = {0,0,0};
long debounceDelay = 50;

/**
  * @reference https://www.arduino.cc/en/Tutorial/Debounce
  */
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
