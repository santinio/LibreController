
void debugInfo(char *info){
#ifdef NRF
#elif PIC32
#else
	#pragma message "No platform defined"
#endif

}

void debugWarning(char *warning){
#ifdef NRF
#elif PIC32
#else
        #pragma message "No platform defined"
#endif
}

void debugError(char * error){
#ifdef NRF
#elif PIC32
#else
        #pragma message "No platform defined"
#endif
}
