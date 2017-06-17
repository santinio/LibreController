#include <stdio.h>
#include <stdlib.h>
#include "../common/debug.h"
#include "../common/controller.h"
#include "../common/controls.h"
#include "timer.h"
#include "adc.h"
#include <stdbool.h>
#include <unistd.h>

myTimer_t timer;
controller_t controller;

void timerCallback()
{
	/*Simplified way to get the data and load them to the controller*/
	adcGet(&controller);
	if(controller.calibrated==false && controller.calibrating == false)
	{
		controllerCalibrateStart(&controller);
		goto update;
	}
	if(controller.calibrating==true)
	{
		controllerCalibrateStop(&controller);
		goto update;
	}
	update:
		controllerUpdateValues(&controller);	
}

int main(){
	DEBUG(DEBUG_NOTE,"Hello LibreController\n");
	//Initialise gpios
	//Initialise controller
	controllerCreate(&controller,5,4,1);
	controlSetPin(&controller.control[0],15);
	//Initialise timers
	timerInit(&timer,&timerCallback,500);
	//Initialise ADC
	adcInit(&controller);
	//Start the ADC
	adcStart();
	//Start timer
	timerStart(&timer);

	while(true)
	{
		sleep(1);
	}
	return EXIT_SUCCESS;
}
