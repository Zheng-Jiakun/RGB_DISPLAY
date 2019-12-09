#ifndef _MUSIC_H_
#define _MUSIC_H_

#include "main.h"
#include "arm_math.h"
#include "arm_const_structs.h"

#define SAMPLE_NUM  512
#define FFT_NUM     SAMPLE_NUM/2

extern float32_t FFTResult[FFT_NUM];

void StartSampling ();
void ProcessFFT ();

#endif