#include "timer.h"
#include <stddef.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../common/debug.h"
#include <time.h>


pthread_t timerThread;
pthread_mutex_t timerLock;

void* fakeTimer(void *data)
{
	myTimer_t *timer;
	timer = (myTimer_t*)data;
	struct timespec ts;
	ts.tv_sec = timer->period / 1000;
	ts.tv_nsec = (timer->period % 1000) * 1000000;
	timer->active = true;
	while(timer->active)
	{
		/*Unlock timer*/
		pthread_mutex_unlock(&timerLock);
		nanosleep(&ts,NULL);
		DEBUG(DEBUG_NOTE,"Timer event.\n");
		timer->callback(NULL);
		/*Lock timer*/
		pthread_mutex_lock(&timerLock);
	}
	pthread_mutex_unlock(&timerLock);
	return NULL;
}

void timerInit(myTimer_t *timer,void *callback,uint16_t period)
{
	if(true)
	{
		timer->active = false;
		timer->period = period;
		timer->callback = callback;
		if(pthread_mutex_init(&timerLock,NULL) != 0)
		{
			DEBUG(DEBUG_WARNING,"Timer mutex failed.\n");
			return;
		}
		DEBUG(DEBUG_NOTE,"Timer initialised.\n");
		return;
	}
	DEBUG(DEBUG_WARNING,"Timer failed to initialised.\n");
}

void timerStart(myTimer_t *timer)
{
	if(timer->period<=0)
	{
		DEBUG(DEBUG_WARNING,"Timer not initialised.\n");
		return;
	}
	int iret1;
	if(timer->active)
	{
		DEBUG(DEBUG_WARNING,"Timer already active\n");
		return;
	}
	iret1 = pthread_create( &timerThread, NULL, &fakeTimer, (void*) timer);
    	if(iret1)
     	{
        	DEBUG(DEBUG_WARNING,"Error - timer thread return code: %d\n",iret1);
     	}
}

void timerStop(myTimer_t *timer)
{
	//A way to notify the thread to stop must be added
}
