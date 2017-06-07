#include <stdio.h>
#include <stdlib.h>
#include "../common/debug.h"
#include "../common/controller.h"
#include "../common/controls.h"

#include "adc.h"

controller_t controller;
int main(){
	DEBUG(DEBUG_NOTE,"Hello LibreController\n");
	//Initialise gpios
	//Initialise controller
	controllerCreate(&controller,5,4,1);
	controlSetPin(&controller.control[0],15);
	//Initialise timers
	//Initialise ADC
	adcInit(&controller);

	return EXIT_SUCCESS;
}
