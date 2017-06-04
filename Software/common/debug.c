
#ifdef NRF52
#include "nrf_log.h"
#elif DEMO
#include <stdio.h>
#endif

void debugInfo(char *info){
#ifdef NRF52
	
#elif PIC32
#elif DEMO
printf("%s\n",info);
#else
	#pragma message "No platform defined"
#endif

}

void debugWarning(char *warning){
#ifdef NRF52
#elif PIC32
#elif DEMO
printf("%s\n",warning);
#else
        #pragma message "No platform defined"
#endif
}

void debugError(char * error){
#ifdef NRF52
#elif PIC32
#elif DEMO
printf("%s\n",error);
#else
        #pragma message "No platform defined"
#endif
}
