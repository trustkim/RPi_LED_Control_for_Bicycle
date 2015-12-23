void runBreakLED(){
  if(curBtnState[BREAK]==HIGH)
    turnOn(RED_BREAK);
  else
    turnOff(RED_BREAK);
}
