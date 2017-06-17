#ifndef TIMER_H_
#define TIMER_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "../common/debug.h"

typedef struct{
	void * (*callback)(void**);
	uint16_t period;
	uint16_t count;
	bool active;
}myTimer_t;

void timerInit(myTimer_t*,void*,uint32_t);
void timerStart(myTimer_t*);
void timerStop(myTimer_t*);

#endif
