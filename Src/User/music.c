#include "music.h"
#include "adc.h"
#include "tim.h"

uint16_t RawSampleResult[RAW_SAMPLE_NUM];

float32_t FFTInput[RAW_SAMPLE_NUM];
float32_t FFTOutput[RAW_SAMPLE_NUM];
float32_t FFTResult[FFT_NUM];

uint16_t FFTSampleResult[FFT_SAMPLE_NUM];

arm_rfft_fast_instance_f32 s;

void StartSampling ()
{
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)RawSampleResult, RAW_SAMPLE_NUM);

    HAL_TIM_Base_Start(&htim6);
    
    arm_rfft_fast_init_f32(&s, RAW_SAMPLE_NUM);
}

void ProcessFFT ()
{
    for (uint16_t i = 0; i < RAW_SAMPLE_NUM; i++)
        FFTInput[i] = RawSampleResult[i];
    arm_rfft_fast_f32(&s, FFTInput, FFTOutput, 0);

  /* Process the data through the Complex Magnitude Module for
  calculating the magnitude at each bin */
    arm_cmplx_mag_f32(FFTOutput, FFTResult, FFT_NUM);

  /* Calculates maxValue and returns corresponding BIN value */
//   arm_max_f32(testOutput, fftSize, &maxValue, &testIndex);

    FFTResultFilter();
}

void FFTResultFilter ()
{
    for (uint8_t i = 0; i < FFT_SAMPLE_NUM; i++)
    {
        FFTSampleResult[i] = 0;
        for (uint8_t j = 0; j < FFT_NUM/FFT_SAMPLE_NUM; j++)
        {
            FFTSampleResult[i] += FFTResult[j+i*(FFT_NUM/FFT_SAMPLE_NUM)];
        }
        FFTSampleResult[i] /= (FFT_NUM/FFT_SAMPLE_NUM);
    }
}