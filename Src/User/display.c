#include "display.h"
#include "WS2812B.h"

color_t DisplayFrameBuffer[PIXEL_ROW][PIXEL_COL];

void PixelToString ()
{
	for (uint8_t col = 0; col < 16; col++)
	{
		for (uint8_t row = 0; row < 16; row++)
		{
			if (col % 2)
				LEDString[PIXEL_ROW*(col+1)-(row+PIXEL_ROW*col)] = DisplayFrameBuffer[row][col];
			else
				LEDString[row+PIXEL_ROW*col] = DisplayFrameBuffer[row][col];
		}
	}
}