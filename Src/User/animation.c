#include "animation.h"

void UpdateColumns (uint8_t ColumnsHeight[PIXEL_COL])
{
    for (uint8_t i = 0; i < 16; i++)
        DisplayFrameBuffer[i][0].r = 0;
    for (uint8_t i = 0; i < height; i++)
        DisplayFrameBuffer[i][0].r = 10;
}