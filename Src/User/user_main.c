#include "main.h"
#include "WS2812B.h"
#include "display.h"
#include "music.h"

// extern color_t DisplayFrameBuffer[PIXEL_ROW][PIXEL_COL];


void Setup (void)
{
    InitLed();
    InitDisplay();
    // StartSampling();
    
    // SelfCheck();
}

void Loop (void)
{
    show_chrome();
    // HAL_Delay(10);
}