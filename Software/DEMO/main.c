#include <stdio.h>
#include <stdlib.h>
#include "../common/debug.h"
#include "../common/controller.h"
#include "../common/controls.h"
#include "timer.h"
#include "adc.h"
#include <stdbool.h>

myTimer_t timer;
controller_t controller;

void timerCallback()
{
	DEBUG(DEBUG_NOTE,"Timer callback triggeres.\n");
}

int main(){
	DEBUG(DEBUG_NOTE,"Hello LibreController\n");
	//Initialise gpios
	//Initialise controller
	controllerCreate(&controller,5,4,1);
	controlSetPin(&controller.control[0],15);
	//Initialise timers
	timerInit(&timer,timerCallback,500);
	//Initialise ADC
	adcInit(&controller);
	//Start timer
	timerStart(&timer);
	while(true)
	{
		sleep(1);
	}
	return EXIT_SUCCESS;
}
