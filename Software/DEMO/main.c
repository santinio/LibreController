#include <stdio.h>
#include <stdlib.h>
#include "../common/debug.h"
#include "../common/controller.h"
#include "../common/controls.h"

#include "adc.h"

controller_t controller;
int main(){
	debugInfo("Hello LibreController");
	//Initialise gpios
	//Initialise controller
	controllerCreate(&controller,5,4,1);
	//Initialise timers
	//Initialise ADC
	adcInit();

	return EXIT_SUCCESS;
}
