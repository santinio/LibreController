#include "../common/debug.h"
#include "../common/controller.h"
#include "../common/debug.h"
//#include <pthreads.h>

void adcInit(controller_t *controller){
	for(int k=0;k<controller->numberOfChannels;k++)
		//Prepare every channel using controller->control[k].adcInput;
		//debugInfo("ADC started");
		DEBUG(DEBUG_NOTE,"ADC pin %d configured\n", k);
}

void adcGet()
{
	/*Check if ADC is initialised*/
	DEBUG(DEBUG_NOTE,"ADC sample\n");
}

void adcStart(){
/*Start a thread with a timer to simulate the adc with timer*/

}
