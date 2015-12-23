#include <wiringPi.h>


/* Pin mapping */
#define RED_BREAK 1	// pin#right 9th
#define YELLOW_LEFT 4	// pin# right 8th
#define YELLOW_RIGHT 5	// pin# right 6th

const int swPinIndexes[3] = {0, 2, 3};
// #define SW_BREAK 0
// #define SW_LEFT 2
// #define SW_RIGHT 3

void callAllPinModes();
