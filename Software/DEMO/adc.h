#ifndef ADC_H_
#define ADC_H_

#include "../common/controller.h"

void adcInit(controller_t*);
void adcGet(controller_t*);
void adcStart();

#endif
