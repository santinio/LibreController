#include <stdio.h>
#include <stdlib.h>
#include "../common/debug.h"
#include "../common/controller.h"
#include "../common/controls.h"

#include "adc.h"

int main(){
	debugInfo("Hello LibreController");
	//Initialise gpios
	//Initialise controller
	
	//Initialise timers
	//Initialise ADC
	adcInit();

	return EXIT_SUCCESS;
}
