#include "debug.h"
#include "stdint.h"
#include "controller.h"

void controllerCreate(controller_t *controller,uint8_t numberOfChannels,uint8_t numberOfAxis, uint8_t numberOfToggles)
{
	if(numberOfChannels!=(numberOfAxis+numberOfToggles))
	{
		debugWarning("Wrong number of controls/channels");
		return;
	}
	if(numberOfChannels>MAX_CHANNELS)
	{
		debugWarning("Too many channels");
		return;
	}
	controller->numberOfChannels = numberOfChannels;
	controller->numberOfAxis = numberOfAxis;
	controller->numberOfToggles = numberOfToggles;
	controller->active = true;
	for(int j=0;j<numberOfChannels;j++)
	{
		controller->control[j].channel = j+1;
		if(numberOfAxis-->0){
			controller->control[j].controlType = CONTROL_TYPE_AXIS;
			debugInfo("Axis added");
		}
		else if(numberOfToggles-->0){
			controller->control[j].controlType = CONTROL_TYPE_TOGGLE;
			debugInfo("Toggle added");
		}
	}
	debugInfo("Controller created");
}

void controllerCalibrate(controller_t *controller)
{

}

void controllerUpdateValues(controller_t *controller)
{
	
}
