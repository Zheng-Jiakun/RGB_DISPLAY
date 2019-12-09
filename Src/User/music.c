#include "music.h"
#include "adc.h"
#include "tim.h"

uint16_t SampleResult[SAMPLE_NUM];
float32_t FFTResult[FFT_NUM];

float32_t FFTInput[SAMPLE_NUM];
float32_t FFTOutput[SAMPLE_NUM];

arm_rfft_fast_instance_f32 s;

void StartSampling ()
{
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)SampleResult, SAMPLE_NUM);

    HAL_TIM_Base_Start(&htim6);
    
    arm_rfft_fast_init_f32(&s, SAMPLE_NUM);
}

void ProcessFFT ()
{
    for (uint16_t i = 0; i < SAMPLE_NUM; i++)
        FFTInput[i] = SampleResult[i];
    arm_rfft_fast_f32(&s, FFTInput, FFTOutput, 0);

  /* Process the data through the Complex Magnitude Module for
  calculating the magnitude at each bin */
  arm_cmplx_mag_f32(FFTOutput, FFTResult, FFT_NUM);

  /* Calculates maxValue and returns corresponding BIN value */
//   arm_max_f32(testOutput, fftSize, &maxValue, &testIndex);
}