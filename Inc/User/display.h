#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "stm32f3xx_hal.h"

#define PIXEL_ROW   16
#define PIXEL_COL   16

void InitDisplay();
void SelfCheck ();
void PixelToString ();
void RefreshDisplay ();

#endif