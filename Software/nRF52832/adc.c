#include "../common/debug.h"
#include "../common/controller.h"
#include "../common/debug.h"
#include "nrf.h"
#include "nrf_drv_saadc.h"
#include "boards.h"
//#include <pthreads.h>

const uint16_t testData[3][MAX_CHANNELS] = \
{{256,500,521,4,5,6,7,8,9,10},\
{0,15,242,12,0,0,0,0,0,0},\
{1024,864,1100,1000,0,0,0,0,0,0}};
//const uint16_t testDataMin[MAX_CHANNELS] = {0,15,242,12,0,0,0};
//const uint16_t testDataMax[MAX_CHANNELS] = {1024,864,1100,1000,1024};
#define ADC_INPUT(X) NRF_SAADC_INPUT_AIN##X

void saadc_callback(nrf_drv_saadc_evt_t const* p_event)
{
	//ret_code_t err_code;
	if(p_event->type==NRF_DRV_SAADC_EVT_DONE)
	{
		DEBUG(DEBUG_NOTE,"ADC event.\n");
	}
}

void adcInit(controller_t *controller){
	ret_code_t err_code;
	nrf_saadc_channel_config_t channel_config = NRF_DRV_SAADC_DEFAULT_CHANNEL_CONFIG_SE(ADC_INPUT(0));
	err_code = nrf_drv_saadc_init(NULL,saadc_callback);
	APP_ERROR_CHECK(err_code);
	err_code = nrf_drv_saadc_channel_init(0, &channel_config);
    	APP_ERROR_CHECK(err_code);
	for(int k=0;k<controller->numberOfChannels;k++)
	{
		//Prepare every channel using controller->control[k].adcInput;
		//debugInfo("ADC started");
		//nrf_saadc_channel_config_t channel_config = NRF_DRV_SAADC_DEFAULT_CHANNEL_CONFIG_SE(ADC_INPUT(k));
        	nrf_saadc_channel_config_t channel_config = 	\
		{                                                  \
		        .resistor_p = NRF_SAADC_RESISTOR_DISABLED,     \
        		.resistor_n = NRF_SAADC_RESISTOR_DISABLED,     \
		        .gain       = NRF_SAADC_GAIN1_6,               \
		        .reference  = NRF_SAADC_REFERENCE_INTERNAL,    \
		        .acq_time   = NRF_SAADC_ACQTIME_10US,          \
		        .mode       = NRF_SAADC_MODE_SINGLE_ENDED,     \
		        .burst      = NRF_SAADC_BURST_DISABLED,        \
		        .pin_p      = (nrf_saadc_input_t)(k),      \
		        .pin_n      = NRF_SAADC_INPUT_DISABLED         \
		 };
		err_code = nrf_drv_saadc_channel_init(k, &channel_config);
        	APP_ERROR_CHECK(err_code);
		DEBUG(DEBUG_NOTE,"ADC pin %d configured\n", k);
	}
	err_code = nrf_drv_saadc_init(NULL,saadc_callback);
        APP_ERROR_CHECK(err_code);
}

void adcGet(controller_t *controller)
{
	static uint8_t count;
	DEBUG(DEBUG_NOTE,"ADC-> ");
	for(int k=0;k<controller->numberOfChannels;k++)
	{
		controller->control[k].adcInput = testData[count][k];
		DEBUG(DEBUG_NOTE,"%d,",controller->control[k].adcInput);
	}
	DEBUG(DEBUG_NOTE,"\n");
	count++;
	if(count>=3)count=0;
	/*Check if ADC is initialised*/
	//DEBUG(DEBUG_NOTE,"ADC sample\n");
}

void adcStart(){
	/*I'll try to use the PPI to load in a buffer that will be accessed by adcGet*/

}
