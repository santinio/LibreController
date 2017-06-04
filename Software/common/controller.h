#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stddef.h>
#include <stdint.h>

typedef struct{
	uint8_t numberOfChannels;
	uint8_t numberOfControls;
	uint8_t numberOfButtons;
}controller_t;
#endif
