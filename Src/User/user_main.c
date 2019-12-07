#include "main.h"
#include "WS2812B.h"
#include "display.h"

uint32_t adc_result;

void Setup (void)
{
    InitLed();
    InitDisplay();

    // HAL_ADCEx_Calibration_Start();
}

void Loop (void)
{
    SelfCheck();
    // if (HAL_ADC_PollForConversion() == HAL_OK)
    // {
    //     adc_result = HAL_ADC_GetValue();
    //     HAL_ADC_Start();
    // }
}