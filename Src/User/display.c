#include "display.h"
#include "WS2812B.h"

color_t DisplayFrameBuffer[PIXEL_ROW][PIXEL_COL];

void InitDisplay ()
{
	InitLed();
}

void SelfCheck ()
{
	for (uint8_t i = 0; i < 16; i++)
	{
		for (uint8_t j = 0; j < 16; j++)
		{
			DisplayFrameBuffer[i][j].r = 10;
			DisplayFrameBuffer[i][j].g = 0;
			DisplayFrameBuffer[i][j].b = 0;
			HAL_Delay(50);
		}
	}
	for (uint8_t i = 0; i < 16; i++)
	{
		for (uint8_t j = 0; j < 16; j++)
		{
			DisplayFrameBuffer[i][j].r = 0;
			DisplayFrameBuffer[i][j].g = 10;
			DisplayFrameBuffer[i][j].b = 0;
			HAL_Delay(50);
		}
	}
	for (uint8_t i = 0; i < 16; i++)
	{
		for (uint8_t j = 0; j < 16; j++)
		{
			DisplayFrameBuffer[i][j].r = 0;
			DisplayFrameBuffer[i][j].g = 0;
			DisplayFrameBuffer[i][j].b = 10;
			HAL_Delay(50);
		}
	}
}

void PixelToString ()
{
	for (uint8_t col = 0; col < PIXEL_COL; col++)
	{
		for (uint8_t row = 0; row < PIXEL_ROW; row++)
		{
			if (col % 2)
				LEDString[row+PIXEL_ROW*col] = DisplayFrameBuffer[PIXEL_ROW-1-row][col];
			else
				LEDString[row+PIXEL_ROW*col] = DisplayFrameBuffer[row][col];
		}
	}
}

void RefreshDisplay ()
{
	PixelToString();
	UpdateLedString();
}