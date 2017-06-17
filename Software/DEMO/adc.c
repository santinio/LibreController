#include "../common/debug.h"
#include "../common/controller.h"
#include "../common/debug.h"
//#include <pthreads.h>

const uint16_t testData[3][MAX_CHANNELS] = \
{{256,500,521,4,5,6,7,8,9,10},\
{0,15,242,12,0,0,0,0,0,0},\
{1024,864,1100,1000,0,0,0,0,0,0}};
//const uint16_t testDataMin[MAX_CHANNELS] = {0,15,242,12,0,0,0};
//const uint16_t testDataMax[MAX_CHANNELS] = {1024,864,1100,1000,1024};

void adcInit(controller_t *controller){
	for(int k=0;k<controller->numberOfChannels;k++)
		//Prepare every channel using controller->control[k].adcInput;
		//debugInfo("ADC started");
		DEBUG(DEBUG_NOTE,"ADC pin %d configured\n", k);
}

void adcGet(controller_t *controller)
{
	static uint8_t count;
	DEBUG(DEBUG_NOTE,"ADC-> ");
	for(int k=0;k<controller->numberOfChannels;k++)
	{
		controller->control[k].adcInput = testData[count][k];
		DEBUG(DEBUG_NOTE,"%d,",controller->control[k].adcInput);
	}
	DEBUG(DEBUG_NOTE,"\n");
	count++;
	if(count>=3)count=0;
	/*Check if ADC is initialised*/
	//DEBUG(DEBUG_NOTE,"ADC sample\n");
}

void adcStart(){
/*Start a thread with a timer to simulate the adc with timer*/

}
