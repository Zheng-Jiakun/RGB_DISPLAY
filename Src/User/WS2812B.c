#include <WS2812B.h>

#define FRAME_SIZE (30 + 24 * LED_NUM + 50)

color_t LEDString[LED_NUM] = {0};

uint16_t DMADataBuf[FRAME_SIZE];

void InitLed()
{
    // HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t *)DMADataBuf, sizeof(*DMADataBuf));
    htim3.hdma[TIM_DMA_ID_UPDATE]->XferCpltCallback = TIM_DMADelayPulseCplt;

    /* Set the DMA error callback */
    htim3.hdma[TIM_DMA_ID_UPDATE]->XferErrorCallback = TIM_DMAError ;

    /* Enable the DMA channel */
    HAL_DMA_Start_IT(htim3.hdma[TIM_DMA_ID_UPDATE], (uint32_t)DMADataBuf, (uint32_t)&htim3.Instance->CCR1, FRAME_SIZE);

    /* Enable the TIM Capture/Compare 1 DMA request */
    __HAL_TIM_ENABLE_DMA(&htim3, TIM_DMA_UPDATE);

    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

void UpdateLedString()
{
    // memset(DMADataBuf, 0, sizeof(DMADataBuf));
    for (uint16_t j = 0; j < LED_NUM; j++)
    {
        for (uint8_t i = 0; i < 8; i++)
        {
            if (LEDString[j].g & (0x80 >> i))
                DMADataBuf[30+j*24+i] = 8;
            else
                DMADataBuf[30+j*24+i] = 4;
        }
        for (uint8_t i = 0; i < 8; i++)
        {
            if (LEDString[j].r & (0x80 >> i))
                DMADataBuf[30+j*24+i+8] = 8;
            else
                DMADataBuf[30+j*24+i+8] = 4;
        }
        for (uint8_t i = 0; i < 8; i++)
        {
            if (LEDString[j].b & (0x80 >> i))
                DMADataBuf[30+j*24+i+16] = 8;
            else
                DMADataBuf[30+j*24+i+16] = 4;
        }
    }
}