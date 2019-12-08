#include "music.h"
#include "adc.h"
#include "arm_math.h"
#include "arm_const_structs.h"

uint16_t SampleResult[SAMPLE_NUM];
float32_t FFTResult[FFT_NUM];

uint32_t ifftFlag = 0;
uint32_t doBitReverse = 1;

void StartSampling ()
{
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)SampleResult, SAMPLE_NUM);
}

void ProcessFFT ()
{
  /* Process the data through the CFFT/CIFFT module */
  arm_cfft_f32(&arm_cfft_sR_f32_len1024, SampleResult, ifftFlag, doBitReverse);

  /* Process the data through the Complex Magnitude Module for
  calculating the magnitude at each bin */
  arm_cmplx_mag_f32(SampleResult, FFTResult, FFT_NUM);
}