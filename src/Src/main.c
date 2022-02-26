#include "STM32F411xx_GPIO.h"
#include "STM32F411xx_DMA.h"

int main(void)
{
	char c1 = 'D';
	char c2;

	DMA2_CLK_ENABLE();

	DMA_StreamInit(DMA2_STREAM3, DMA_Channel3, DATA_8_BIT, DATA_8_BIT, MEM_TO_MEM, FIXED_MODE, DMA_LOW_PRIORITY);
	DMA_SetDataAddress(DMA2_STREAM3, (uint32_t*)&c2, (uint32_t*)&c1);
	DMA_SetNumberOfDataItems(DMA2_STREAM3, 1);

	DMA_EnableStream(DMA2_STREAM3);
	DMA_DisableStream(DMA2_STREAM3);

	while (1)
	{

	}
	return 0;
}
