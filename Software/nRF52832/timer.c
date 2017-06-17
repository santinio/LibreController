#include "timer.h"
#include <stddef.h>
//#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../common/debug.h"
//#include <time.h>
#include "nrf.h"
#include "nrf_drv_timer.h"
#include "bsp.h"
#include "app_error.h"

/*
pthread_t timerThread;
pthread_mutex_t timerLock;
*/
const nrf_drv_timer_t TIMER_TEST = NRF_DRV_TIMER_INSTANCE(0);

void* fakeTimer(void *data)
{
	/*
	myTimer_t *timer;
	timer = (myTimer_t*)data;
	struct timespec ts;
	ts.tv_sec = timer->period / 1000;
	ts.tv_nsec = (timer->period % 1000) * 1000000;
	timer->active = true;
	
	while(timer->active)
	{
		//Unlock timer
		pthread_mutex_unlock(&timerLock);
		nanosleep(&ts,NULL);
		DEBUG(DEBUG_NOTE,"Timer event.\n");
		timer->callback(NULL);
		//Lock timer
		pthread_mutex_lock(&timerLock);
	}
	pthread_mutex_unlock(&timerLock);
	*/
	return NULL;
}

void timerInit(myTimer_t *timer,void *callback,uint32_t period)
{
/*
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
*/
	uint32_t time_ticks;
	//uint32_t time_us = 22500;
	uint32_t err_code = NRF_SUCCESS;
	nrf_drv_timer_config_t timer_cfg = NRF_DRV_TIMER_DEFAULT_CONFIG;
	err_code = nrf_drv_timer_init(&TIMER_TEST,&timer_cfg,callback);
	APP_ERROR_CHECK(err_code);
	time_ticks = nrf_drv_timer_us_to_ticks(&TIMER_TEST, period);
	nrf_drv_timer_extended_compare(&TIMER_TEST, NRF_TIMER_CC_CHANNEL0, time_ticks, NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK, true);
	DEBUG(DEBUG_WARNING,"Timer failed to initialised.\n");
}

void timerStart(myTimer_t *timer)
{
	/*
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
	*/
}

void timerStop(myTimer_t *timer)
{
	//A way to notify the thread to stop must be added
}
