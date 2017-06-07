#include "timer.h"
#include <stddef.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../common/debug.h"
#include <time.h>

pthread_t timerThread;

void* fakeTimer(void *data)
{
	DEBUG(DEBUG_NOTE,"Hello from thread\n");
	myTimer_t *timer;
	timer = (myTimer_t*)data;
	struct timespec ts;
	ts.tv_sec = timer->period / 1000;
	ts.tv_nsec = (timer->period % 1000) * 1000000;
	while(true)
	{
		nanosleep(&ts,NULL);
		DEBUG(DEBUG_NOTE,"Timer event.\n");
	}
}

void timerInit(myTimer_t *timer,void *callback,uint16_t period)
{
	if(timer!=NULL)
	{
		timer->period = period;
		timer->callback = callback;
		DEBUG(DEBUG_NOTE,"Timer initialised.\n");
		return;
	}
	DEBUG(DEBUG_WARNING,"Timer failed to initialised.\n");
}

void timerStart(myTimer_t *timer)
{
	int iret1;
	iret1 = pthread_create( &timerThread, NULL, &fakeTimer, (void*) timer);
    	if(iret1)
     	{
        	DEBUG(DEBUG_WARNING,"Error - timer thread return code: %d\n",iret1);
     	}
}

void timerStop(myTimer_t *timer)
{

}
