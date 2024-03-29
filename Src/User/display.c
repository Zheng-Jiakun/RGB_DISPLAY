#include "display.h"

color_t DisplayFrameBuffer[PIXEL_ROW][PIXEL_COL];

void InitDisplay ()
{
	InitLed();
	HAL_TIM_Base_Start_IT(&htim7);
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
			HAL_Delay(CHECK_SPEED);
		}
	}
	for (uint8_t i = 0; i < 16; i++)
	{
		for (uint8_t j = 0; j < 16; j++)
		{
			DisplayFrameBuffer[i][j].r = 0;
			DisplayFrameBuffer[i][j].g = 10;
			DisplayFrameBuffer[i][j].b = 0;
			HAL_Delay(CHECK_SPEED);
		}
	}
	for (uint8_t i = 0; i < 16; i++)
	{
		for (uint8_t j = 0; j < 16; j++)
		{
			DisplayFrameBuffer[i][j].r = 0;
			DisplayFrameBuffer[i][j].g = 0;
			DisplayFrameBuffer[i][j].b = 10;
			HAL_Delay(CHECK_SPEED);
		}
	}
	for (uint8_t i = 0; i < 16; i++)
	{
		for (uint8_t j = 0; j < 16; j++)
		{
			DisplayFrameBuffer[i][j].r = 0;
			DisplayFrameBuffer[i][j].g = 0;
			DisplayFrameBuffer[i][j].b = 0;
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

uint8_t chrome[256][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 64, 64},
    {224, 64, 64},
    {224, 64, 64},
    {224, 64, 64},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 64, 64},
    {224, 64, 64},
    {224, 64, 64},
    {224, 64, 64},
    {224, 64, 64},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {128, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 128, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {224, 96, 64},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {64, 160, 64},
    {192, 64, 64},
    {224, 64, 64},
    {224, 96, 64},
    {192, 192, 192},
    {166, 202, 240},
    {166, 202, 240},
    {192, 220, 192},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {32, 160, 128},
    {32, 160, 128},
    {96, 128, 64},
    {192, 64, 64},
    {192, 192, 192},
    {96, 160, 192},
    {64, 128, 192},
    {64, 128, 192},
    {96, 160, 192},
    {192, 220, 192},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {0, 0, 0},
    {0, 0, 0},
    {32, 160, 128},
    {32, 160, 128},
    {32, 160, 128},
    {160, 96, 64},
    {166, 202, 240},
    {64, 128, 192},
    {64, 128, 192},
    {64, 128, 192},
    {64, 128, 192},
    {166, 202, 240},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {0, 0, 0},
    {0, 0, 0},
    {32, 160, 128},
    {32, 160, 128},
    {32, 160, 128},
    {96, 128, 64},
    {166, 202, 240},
    {64, 128, 192},
    {64, 128, 192},
    {64, 128, 192},
    {64, 128, 192},
    {166, 202, 240},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {0, 0, 0},
    {0, 0, 0},
    {32, 160, 128},
    {32, 160, 128},
    {32, 160, 128},
    {32, 160, 128},
    {192, 220, 192},
    {96, 160, 192},
    {64, 128, 192},
    {64, 128, 192},
    {96, 160, 192},
    {192, 220, 192},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {32, 160, 64},
    {32, 160, 64},
    {32, 160, 64},
    {32, 160, 128},
    {192, 220, 192},
    {166, 202, 240},
    {166, 202, 240},
    {192, 220, 192},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {32, 160, 64},
    {32, 160, 64},
    {32, 160, 64},
    {32, 160, 64},
    {32, 160, 64},
    {32, 160, 128},
    {32, 160, 128},
    {160, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {32, 160, 64},
    {32, 160, 64},
    {32, 160, 64},
    {32, 160, 64},
    {32, 160, 64},
    {32, 160, 64},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {32, 160, 64},
    {32, 160, 64},
    {32, 160, 64},
    {32, 160, 64},
    {192, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {224, 192, 64},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {32, 160, 64},
    {64, 160, 64},
    {224, 192, 64},
    {224, 192, 64},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
};

void show_chrome ()
{
	for (uint8_t i = 0; i < 16; i++)
	{
		for (uint8_t j = 0; j < 16; j++)
		{
			DisplayFrameBuffer[i][j].r = chrome[j+(i*16)][0];
			DisplayFrameBuffer[i][j].g = chrome[j+(i*16)][1];
			DisplayFrameBuffer[i][j].b = chrome[j+(i*16)][2];
		}
	}
}