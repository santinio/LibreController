#include "controls.h"
#include "stdbool.h"
#include "memory-buffers/src/bufferMemory.h"
#include "stdint.h"
#include "stddef.h"
#include "../common/debug.h"
//#include "nrf_log.h"
#include "controller.h"
//#define NUMBER_OF_CONTROLS 5

controller_t controller;

//static uint8_t adcInputs[5] = {0,1,2,3,4};
static CONTROLS_STATE controlsState;

buffer_t controlsBuffer;
bool controlsInit(){
int count=0;
control_t control;
	if(controlsState==CONTROLS_STATE_OFF){
		/*Enable the controls*/
		bufferCreate(&controlsBuffer,BUFFER_TYPE_LINKED,sizeof(control_t),controller.numberOfChannels,&controlAlloc,&controlFree,&controlError);
		for(count=0;count<controller.numberOfChannels;count++){
			control.id=count;
			if(bufferAddData(&controlsBuffer,&control,sizeof(control_t))!=BUFFER_STATUS_OK){
				//NRF_LOG_INFO("Not enough memory to store controls\r\n");
				return false;
			}
		}
		//NRF_LOG_INFO("Controls added in buffer\r\n");
		/*Enable the ADC channels*/
		controlsState=CONTROLS_STATE_INITIALISED;
		return true;
	}
	return false;
}

bool controlsDeInit(){
	if(controlsState==CONTROLS_STATE_STOPPED)
		return true;
	return false;
}
bool controlsStartSampling(){
	if(controlsState==CONTROLS_STATE_INITIALISED)
		/*Start timer?adc?pwm?*/
		return true;
	return false;
}
bool controlsStopSampling(){
	if(controlsState==CONTROLS_STATE_ACTIVATED)
		return true;
	return false;
}

void controlAlloc(){
}
void controlFree(){
}
void controlError(){
}


void controlSetType(control_t *control,CONTROL_TYPE type)
{
	control->controlType = type;
}
void controlSetChannel(control_t *control, uint8_t channel)
{
	control->channel = channel;
}
void controlCreate(control_t *control,uint8_t adcChannel)
{

}
void controlSetPin(control_t *control,uint8_t pin)
{
	DEBUG(DEBUG_NOTE,"set pin");
}
