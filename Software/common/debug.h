#ifndef DEBUG_H_
#define DEBUG_H_

/*Generate platform specific debug functions*/

#define DEBUG_OFF 0
#define DEBUG_ERROR 1
#define DEBUG_WARNING 2
#define DEBUG_NOTE 3

#define DEBUG_ERROR_STRING "Error"
#define DEBUG_WARNING_STRING "Warning"
#define DEBUG_NOTE_STRING "Note"

#define DEBUG_STRING(Y) STRING##Y
#define STRING1 DEBUG_ERROR_STRING
#define STRING2 DEBUG_WARNING_STRING
#define STRING3 DEBUG_NOTE_STRING

#define DEBUG(X,...) printf(X,##__VA_ARGS__)

#ifdef DEMO
#define DEBUG_(Y,X,...) do { \
    if(DEBUG_LEVEL>=Y)printf(X,##__VA_ARGS__); \
    }while(0)
#elif PIC32
#elif NRF52
#endif


void debugInfo(char*);
void debugWarning(char*);
void debugError(char*);

#endif
