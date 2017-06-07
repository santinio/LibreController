#ifndef CONTROLS_H_
#define CONTROLS_H_
#include "stdbool.h"
#include "stdint.h"
typedef enum{
	CONTROLS_STATE_UNINITIALISED,
	CONTROLS_STATE_OFF,
	CONTROLS_STATE_INITIALISED,
	CONTROLS_STATE_ACTIVATED,
	CONTROLS_STATE_STOPPED,
	CONTROLS_STATE_ERROR,
}CONTROLS_STATE;

typedef enum{
	CONTROL_TYPE_AXIS,
	CONTROL_TYPE_TOGGLE,
	CONTROL_TYPE_SWITCH,
}CONTROL_TYPE;

typedef struct{
	uint8_t id;
	uint8_t channel;
	uint16_t minimum;
	uint16_t maximum;
	uint16_t center;
	uint16_t value;
	uint16_t adcInput;
	CONTROL_TYPE controlType; 
	char *name;
}control_t;

bool controlsInit();
bool controlsDeInit();
bool controlsStartSampling();
bool controlsStopSampling();
void controlAlloc();
void controlFree();
void controlError();
void controlSetType(control_t*,CONTROL_TYPE);
void controlSetChannel(control_t*, uint8_t);
void controlCreate(control_t*,uint8_t);
void controlSetPin(control_t*,uint8_t);
#endif
