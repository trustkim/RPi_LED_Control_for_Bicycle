/**
  * @file breakLED.c
  * @author lastman (junho5656@naver.com)
  * @version v1.0
  */

void runBreakLED(){
  if(curBtnState[BREAK]==HIGH)
    turnOn(RED_BREAK);
  else
    turnOff(RED_BREAK);
}
