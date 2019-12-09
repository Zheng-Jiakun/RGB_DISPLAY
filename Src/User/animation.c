#include "animation.h"

void ClearPixel (uint8_t row, uint8_t col)
{
    DisplayFrameBuffer[row][col].r = 0;
    DisplayFrameBuffer[row][col].g = 0;
    DisplayFrameBuffer[row][col].b = 0;
}

void SetPixel (uint8_t row, uint8_t col)
{
    if (col >= 14 && col < 16)
    {
        DisplayFrameBuffer[row][col].r = 255/BRIGHTNESS;
        DisplayFrameBuffer[row][col].g = 100/BRIGHTNESS;
        DisplayFrameBuffer[row][col].b = 255/BRIGHTNESS;
    }
    else if (col >= 12 && col < 14)
    {
        DisplayFrameBuffer[row][col].r = 148/BRIGHTNESS;
        DisplayFrameBuffer[row][col].g = 0/BRIGHTNESS;
        DisplayFrameBuffer[row][col].b = 211/BRIGHTNESS;
    }
    else if (col >= 10 && col < 12)
    {
        DisplayFrameBuffer[row][col].r = 75/BRIGHTNESS;
        DisplayFrameBuffer[row][col].g = 0/BRIGHTNESS;
        DisplayFrameBuffer[row][col].b = 130/BRIGHTNESS;
    }
    else if (col >= 8 && col < 10)
    {
        DisplayFrameBuffer[row][col].r = 0/BRIGHTNESS;
        DisplayFrameBuffer[row][col].g = 0/BRIGHTNESS;
        DisplayFrameBuffer[row][col].b = 255/BRIGHTNESS;
    }
    else if (col >= 6 && col < 8)
    {
        DisplayFrameBuffer[row][col].r = 0/BRIGHTNESS;
        DisplayFrameBuffer[row][col].g = 255/BRIGHTNESS;
        DisplayFrameBuffer[row][col].b = 0/BRIGHTNESS;
    }
    else if (col >= 4 && col < 6)
    {
        DisplayFrameBuffer[row][col].r = 255/BRIGHTNESS;
        DisplayFrameBuffer[row][col].g = 255/BRIGHTNESS;
        DisplayFrameBuffer[row][col].b = 0/BRIGHTNESS;
    }
    else if (col >= 2 && col < 4)
    {
        DisplayFrameBuffer[row][col].r = 255/BRIGHTNESS;
        DisplayFrameBuffer[row][col].g = 127/BRIGHTNESS;
        DisplayFrameBuffer[row][col].b = 0/BRIGHTNESS;
    }
    else if (col >= 0 && col < 2)
    {
        DisplayFrameBuffer[row][col].r = 255/BRIGHTNESS;
        DisplayFrameBuffer[row][col].g = 0/BRIGHTNESS;
        DisplayFrameBuffer[row][col].b = 0/BRIGHTNESS;
    }
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