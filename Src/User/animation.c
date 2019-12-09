#include "animation.h"

void ClearPixel (uint8_t row, uint8_t col)
{
    DisplayFrameBuffer[row][col].r = 0;
    DisplayFrameBuffer[row][col].g = 0;
    DisplayFrameBuffer[row][col].b = 0;
}

void SetPixel (uint8_t row, uint8_t col)
{
    DisplayFrameBuffer[row][col].r = 255/16;
    DisplayFrameBuffer[row][col].g = 179/16;
    DisplayFrameBuffer[row][col].b = 214/16;
}

void UpdateColumns (uint8_t ColumnsHeight[PIXEL_COL])
{
    static uint8_t LastColumnsHeight[PIXEL_COL];
    for (uint8_t col = 0; col < PIXEL_COL; col++)
    {
        if (ColumnsHeight[col] > PIXEL_ROW)
            ColumnsHeight[col] = PIXEL_ROW;
        if (LastColumnsHeight[col] > ColumnsHeight[col])
        {
            ClearPixel(LastColumnsHeight[col]-1, col);
            LastColumnsHeight[col]--;
        }
        else if (LastColumnsHeight[col] < ColumnsHeight[col])
        {
            SetPixel(LastColumnsHeight[col], col);
            LastColumnsHeight[col]++;
        }
        HAL_Delay(SLIDE_SPEED);
    }
}