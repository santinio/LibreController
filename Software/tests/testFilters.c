#include "../common/debug.h"
#include "../common/filters.h"
#include <stddef.h>
#include <stdint.h>

uint16_t testData[] = {1,2,3,2,1,3,2};


int main()
{
	uint16_t result;
	DEBUG(DEBUG_NOTE,"Filter testing.\n");
	result = filterAverage(testData,sizeof(testData)/sizeof(uint16_t));
	DEBUG(DEBUG_NOTE,"Average result = %d.\n",result);
}
