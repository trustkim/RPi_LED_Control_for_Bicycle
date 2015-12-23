void runBreakLED(){
  int sw1=digitalRead(SW_BREAK);
  if(sw1=HIGH)
    turnOn(RED_BREAK);
  else
    turnOff(RED_BREAK);
}
