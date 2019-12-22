#include "main.h"
#include "WS2812B.h"
#include "display.h"
#include "music.h"
#include "animation.h"

// extern color_t DisplayFrameBuffer[PIXEL_ROW][PIXEL_COL];

uint8_t ColumnHeights[PIXEL_COL];

void CalibrateCoefficient (uint8_t ColumnData[PIXEL_COL], uint16_t* s, uint16_t ScaleMin, uint16_t ScaleMax)
{
    uint16_t Max = 0;
    for (uint8_t i = 0; i < PIXEL_COL; i++)
        if (ColumnData[i] > Max)
            Max = ColumnData[i];
    if (Max > PIXEL_ROW - 1)
        (*s) += 50;
    else if (Max < 8)
        (*s) -= 50;
    
    if (*s <= ScaleMin)
        *s = ScaleMin;
    else if (*s >= ScaleMax)
        *s = ScaleMax;
}

void Setup (void)
{
    InitLed();
    InitDisplay();
    StartSampling();
    
    // SelfCheck();
}

void Loop (void)
{
    static uint16_t Scale = 1000;
    for (uint8_t col = 0; col < PIXEL_COL; col++)
        ColumnHeights[15-col] = FFTSampleResult[col] * 1.0f / Scale * PIXEL_ROW;  //FFT_NUM/PIXEL_COL*(col+1)
    UpdateColumns(ColumnHeights);

    CalibrateCoefficient(ColumnHeights, &Scale, 50, 2000);

    // show_chrome();
    // HAL_Delay(10);
}