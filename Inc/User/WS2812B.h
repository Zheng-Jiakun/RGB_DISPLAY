#ifndef _WS2812B_H_
#define _WS2812B_H_

#include "stm32f3xx_hal.h"
#include "display.h"

#define LED_NUM     (PIXEL_COL*PIXEL_ROW)

typedef struct 
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} color_t;

extern color_t LEDString[LED_NUM];
void InitLed ();
void UpdateLedString ();

#endif