#include "debug.h"
#include "stdint.h"
#include "controller.h"

const uint16_t testDataMin[MAX_CHANNELS] = {0,15,242,12,0,0,0};
const uint16_t testDataMax[MAX_CHANNELS] = {1024,500,1100,1000,1024};
extern const uint16_t testData[MAX_CHANNELS] ;

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
		controlCreate(&controller->control[j]);
		controller->control[j].channel = j+1;
		if(numberOfAxis-->0){
			controlSetType(&controller->control[j],CONTROL_TYPE_AXIS);
			//controller->control[j].controlType = CONTROL_TYPE_AXIS;
			debugInfo("Axis added");
		}
		else if(numberOfToggles-->0){
			controlSetType(&controller->control[j],CONTROL_TYPE_TOGGLE);
			//controller->control[j].controlType = CONTROL_TYPE_TOGGLE;
			debugInfo("Toggle added");
		}
	}
	debugInfo("Controller created");
}

void controllerCalibrateStart(controller_t *controller)
{
	if(controller->calibrating==false)
	{
		controller->calibrating = true;
		DEBUG(DEBUG_NOTE,"Calibration started\n");
	}
	else
	{
		DEBUG(DEBUG_WARNING,"Already in calibration mode\n");
	}
}

void controllerCalibrateStop(controller_t *controller)
{
	if(controller->calibrating)
	{
		controller->calibrating = false;
		controller->calibrated = true;
		DEBUG(DEBUG_NOTE,"Calibrated\n");
	}
	else
	{
		DEBUG(DEBUG_WARNING,"Stopping calibration without starting it\n");
	}
}
void controllerUpdateValues(controller_t *controller)
{
	if(controller->calibrating)
	{
		for(int j=0;j<controller->numberOfChannels;j++)
 	        {
			controlCalibrate(&controller->control[j]);
        	}
	}
	else if((controller->calibrating == false)&&(controller->calibrated==false))
	{
		for(int j=0;j<controller->numberOfChannels;j++)
                {
                        //controlCalibrate(&controller->control[j]);
                }
	}
	else
	{
		DEBUG(DEBUG_NOTE,"Calculated-> ")
		for(int j=0;j<controller->numberOfChannels;j++)
                {
                        controlCalculate(&controller->control[j]);
                	DEBUG(DEBUG_NOTE,"%d,",controller->control[j].value);
		}
		DEBUG(DEBUG_NOTE,"\n");
	}
}

