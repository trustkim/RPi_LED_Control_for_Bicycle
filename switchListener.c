#define BT_STATE_OFF 0
#define BT_STATE_ON 1

int btBreakState = BT_STATE_OFF;
int btLeftState = BT_STATE_OFF;
int btRightState = BT_STATE_OFF;

int checkButtonState(int PIN_NUM) {
  return digitalRead(PIN_NUM);
}

void updateButtonState() {
  btBreakState = checkButtonState(SW_BREAK);
  btLeftState = checkButtonState(SW_LEFT);
  btRightState = checkButtonState(SW_RIGHT);
}
