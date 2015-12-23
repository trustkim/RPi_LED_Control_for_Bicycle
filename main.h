/**
  * @file main.h
  * @author TK (trustkim@pukyong.ac.kr), lastman (junho5656@naver.com)
  * @version v1.0
  */

#include <wiringPi.h>

/* Pin mapping */
#define RED_BREAK 1	// pin#right 9th
#define YELLOW_LEFT 4	// pin# right 8th
#define YELLOW_RIGHT 5	// pin# right 6th

const int swPinIndexes[3] = {0, 2, 3};

void callAllPinModes();
