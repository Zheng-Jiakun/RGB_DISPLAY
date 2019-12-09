#include "animation.h"

void UpdateColumns (uint8_t ColumnsHeight[PIXEL_COL])
{
    for (uint8_t col = 0; col < PIXEL_COL; col++)
    {
        if (col >= 0 && col < 5)
        {
            for (uint8_t i = 0; i < PIXEL_ROW; i++)
                DisplayFrameBuffer[i][col].b = 0;
            for (uint8_t i = 0; i < ColumnsHeight[col]; i++)
                DisplayFrameBuffer[i][col].b = 10;
        }
        else if (col >= 5 && col < 10)
        {
            for (uint8_t i = 0; i < PIXEL_ROW; i++)
                DisplayFrameBuffer[i][col].g = 0;
            for (uint8_t i = 0; i < ColumnsHeight[col]; i++)
                DisplayFrameBuffer[i][col].g = 10;
        }
        else if (col >= 10 && col < 16)
        {
            for (uint8_t i = 0; i < PIXEL_ROW; i++)
                DisplayFrameBuffer[i][col].r = 0;
            for (uint8_t i = 0; i < ColumnsHeight[col]; i++)
                DisplayFrameBuffer[i][col].r = 10;
        }
    }
}