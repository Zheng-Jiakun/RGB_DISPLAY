#ifndef _MUSIC_H_
#define _MUSIC_H_

#include "main.h"

#define SAMPLE_NUM  2048
#define FFT_NUM     SAMPLE_NUM/2

extern uint16_t SampleResult[SAMPLE_NUM];

void StartSampling ();
void ProcessFFT ();

#endif