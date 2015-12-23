#define BT_STATE_OFF 0  // LOW -> LOW
#define BT_STATE_UP 1   // LOW -> HIGH
#define BT_STATE_ON 2   // HIGH -> HIGH
#define BT_STATE_DOWN 3 // HIGH -> LOW

int btBreakState = BT_STATE_OFF;
int btLeftState = BT_STATE_OFF;
int btRightState = BT_STATE_OFF;

// int debouncedReadButton(int PIN_NUM) {
//   return digitalRead(PIN_NUM);
// }

int checkButtonState(int PIN_NUM) {
  return digitalRead(PIN_NUM);
}

void updateButtonState() {
  btBreakState = checkButtonState(SW_BREAK);
  btLeftState = checkButtonState(SW_LEFT);
  btRightState = checkButtonState(SW_RIGHT);
}
