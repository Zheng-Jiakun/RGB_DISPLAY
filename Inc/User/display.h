#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "main.h"
#include "tim.h"
#include "WS2812B.h"

#define PIXEL_ROW 16
#define PIXEL_COL 16

// typedef struct
// {
//     uint8_t r;
//     uint8_t g;
//     uint8_t b;
// } color_t;

extern color_t DisplayFrameBuffer[PIXEL_ROW][PIXEL_COL];

void InitDisplay();
void SelfCheck();
void PixelToString();
void RefreshDisplay();
void show_chrome();

#endif