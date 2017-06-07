#include <stdint.h>
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

void debugSend(uint8_t *status,uint8_t *function,uint8_t *data)
{
    int numberOfBytes = 0;
    uint8_t string[127]= {0};
    /*We need to add a safety limit to avoid overflows
     !!!CAUTION HERE!!! The extra characters added to the string 
     * need to be counted also. "[ in ]\n" 
     I'm adding 7*/
    numberOfBytes = strlen(status) + strlen(data) + strlen(function);
    if(numberOfBytes>127)numberOfBytes = 127;
    /*Need to add the data in the appropriate buffer*/
    sprintf(string,"[%s in %s]%s\n",status,function,data);
    /*Now add the data to the buffer*/    
	printf("%s\n",string);
    //bufferAddData(&bufferUSBDebugSend,string,numberOfBytes);
}

