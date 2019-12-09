#ifndef _MUSIC_H_
#define _MUSIC_H_

#include "main.h"
#include "arm_math.h"
#include "arm_const_structs.h"

#define FFT_SAMPLE_NUM    16

#define RAW_SAMPLE_NUM  2048
#define FFT_NUM     RAW_SAMPLE_NUM/2

extern float32_t FFTResult[FFT_NUM];
extern uint16_t FFTSampleResult[FFT_SAMPLE_NUM];

void StartSampling ();
void ProcessFFT ();
void FFTResultFilter ();

#endif