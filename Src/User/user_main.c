#include "main.h"
#include "WS2812B.h"
#include "display.h"
#include "music.h"
#include "animation.h"

// extern color_t DisplayFrameBuffer[PIXEL_ROW][PIXEL_COL];

uint8_t ColumnHeights[PIXEL_COL];

void Setup (void)
{
    InitLed();
    InitDisplay();
    StartSampling();
    
    // SelfCheck();
}

void Loop (void)
{
    for (uint8_t col = 0; col < PIXEL_COL; col++)
        ColumnHeights[15-col] = FFTSampleResult[col]/1400.0f*PIXEL_ROW;  //FFT_NUM/PIXEL_COL*(col+1)
    UpdateColumns(ColumnHeights);
    // show_chrome();
    // HAL_Delay(10);
}