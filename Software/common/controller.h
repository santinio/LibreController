#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stddef.h>
#include <stdint.h>
#include "controls.h"
#include "stdbool.h"

typedef struct{
	uint8_t numberOfChannels;
	uint8_t numberOfAxis;
	uint8_t numberOfToggles;
	control_t control[MAX_CHANNELS];
	bool	active;
}controller_t;

void controllerCreate(controller_t*,uint8_t,uint8_t,uint8_t);
void controllerCalibrate(controller_t*);
void controllerUpdateValues(controller_t*);
#endif
