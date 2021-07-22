#ifndef DELAY

#define DELAY
#include <time.h>
/*
	function to create delay
*/

void delay(int no_of_second){
	int milliseconds = 1000 * no_of_second;
	long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

#endif