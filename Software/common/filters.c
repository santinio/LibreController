#include "debug.h"
#include <stddef.h>
#include <stdint.h>

uint16_t filterAverage(uint16_t *data, uint16_t size)
{
	uint32_t sum=0;
	uint16_t result =0;
	int count;
	for(count=0;count<size;count++)
	{
		sum = sum + *(data+count);
	}
	result = sum/size;
	DEBUG(DEBUG_NOTE,"Sum is %d.\n",sum);
	DEBUG(DEBUG_NOTE,"Size is %d.\n",size);
	DEBUG(DEBUG_NOTE,"Average is %d.\n",result);
	return result;
}
