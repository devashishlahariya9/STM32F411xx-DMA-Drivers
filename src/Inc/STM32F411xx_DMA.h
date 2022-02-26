/*
 * STM32F411xx_DMA.h
 *
 * Created on: 12-Nov-2021
 * Author: Devashish Lahariya
*/

#ifndef STM32F411XX_DMA_H_
#define STM32F411XX_DMA_H_

#include <stdint.h>
#include "STM32F411xx.h"

//DMA->LISR
#define DMA_FEIF0	0U
#define DMA_DMEIF0	2U
#define DMA_TEIF0	3U
#define DMA_HTIF0	4U
#define DMA_TCIF0	5U
#define DMA_FEIF1	6U
#define DMA_DMEIF1	8U
#define DMA_TEIF1	9U
#define DMA_HTIF1	10U
#define DMA_TCIF1	11U
#define DMA_FEIF2	16U
#define DMA_DMEIF2	18U
#define DMA_TEIF2	19U
#define DMA_HTIF2	20U
#define DMA_TCIF2	21U
#define DMA_FEIF3	22U
#define DMA_DMEIF3	24U
#define DMA_TEIF3	25U
#define DMA_HTIF3	26U
#define DMA_TCIF3	27U

//DMA -> HISR
#define DMA_FEIF4	0U
#define DMA_DMEIF4	2U
#define DMA_TEIF4	3U
#define DMA_HTIF4	4U
#define DMA_TCIF4	5U
#define DMA_FEIF5	6U
#define DMA_DMEIF5	8U
#define DMA_TEIF5	9U
#define DMA_HTIF5	10U
#define DMA_TCIF5	11U
#define DMA_FEIF6	16U
#define DMA_DMEIF6	18U
#define DMA_TEIF6	19U
#define DMA_HTIF6	20U
#define DMA_TCIF6	21U
#define DMA_FEIF7	22U
#define DMA_DMEIF7	24U
#define DMA_TEIF7	25U
#define DMA_HTIF7	26U
#define DMA_TCIF7	27U

//DMA -> LIFCR
#define DMA_CFEIF0	0U
#define DMA_CDMEIF0	2U
#define DMA_CTEIF0	3U
#define DMA_CHTIF0	4U
#define DMA_CTCIF0	5U
#define DMA_CFEIF1	6U
#define DMA_CDMEIF1	8U
#define DMA_CTEIF1	9U
#define DMA_CHTIF1	10U
#define DMA_CTCIF1	11U
#define DMA_CFEIF2	16U
#define DMA_CDMEIF2	18U
#define DMA_CTEIF2	19U
#define DMA_CHTIF2	20U
#define DMA_CTCIF2	21U
#define DMA_CFEIF3	22U
#define DMA_CDMEIF3	24U
#define DMA_CTEIF3	25U
#define DMA_CHTIF3	26U
#define DMA_CTCIF3	27U

//DMA -> HIFCR
#define DMA_CFEIF4	0U
#define DMA_CDMEIF4	2U
#define DMA_CTEIF4	3U
#define DMA_CHTIF4	4U
#define DMA_CTCIF4	5U
#define DMA_CFEIF5	6U
#define DMA_CDMEIF5	8U
#define DMA_CTEIF5	9U
#define DMA_CHTIF5	10U
#define DMA_CTCIF5	11U
#define DMA_CFEIF6	16U
#define DMA_CDMEIF6	18U
#define DMA_CTEIF6	19U
#define DMA_CHTIF6	20U
#define DMA_CTCIF6	21U
#define DMA_CFEIF7	22U
#define DMA_CDMEIF7	24U
#define DMA_CTEIF7	25U
#define DMA_CHTIF7	26U
#define DMA_CTCIF7	27U

//DMA -> SxCR
#define DMA_EN		0U
#define DMA_DMEIE	1U
#define DMA_TEIE	2U
#define DMA_HTIE	3U
#define DMA_TCIE	4U
#define DMA_PFCTRL	5U
#define DMA_DIR		6U
#define DMA_CIRC	8U
#define DMA_PINC	9U
#define DMA_MINC	10U
#define DMA_PSIZE	11U
#define DMA_MSIZE	13U
#define DMA_PINCOS	15U
#define DMA_PL		16U
#define DMA_DBM		18U
#define DMA_CT		19U
#define DMA_PBURST	21U
#define DMA_MBURST	23U
#define DMA_CHSEL	25U

//DMA -> SxFCR
#define DMA_FTH		0U
#define DMA_DMDIS	2U
#define DMA_FS		3U
#define DMA_FEIE	7U

#define DMA1_ADDRESS 0x40026000
#define DMA2_ADDRESS 0x40026400

#define DMA1_CLK_ENABLE()	(RCC -> AHB1ENR |= (1 << DMA1EN))
#define DMA2_CLK_ENABLE()	(RCC -> AHB1ENR |= (1 << DMA2EN))

#define DMA1_CLK_DISABLE()	(RCC -> AHB1ENR &= ~(1 << DMA1EN))
#define DMA2_CLK_DISABLE()	(RCC -> AHB1ENR &= ~(1 << DMA2EN))

enum DMA_DATA_MODES
{
	DATA_8_BIT,
	DATA_16_BIT,
	DATA_32_BIT
};

enum DMA_POINTER_MODES
{
	FIXED_MODE,
	SOURCE_AUTO_INC,
	DEST_AUTO_INC,
	SD_AUTO_INC
};

enum DMA_DIR_MODES
{
	PERI_TO_MEM,
	MEM_TO_PERI,
	MEM_TO_MEM
};

enum DMA_Streams
{
	DMA_Stream0,
	DMA_Stream1,
	DMA_Stream2,
	DMA_Stream3,
	DMA_Stream4,
	DMA_Stream5,
	DMA_Stream6,
	DMA_Stream7
};

enum DMA_Channels
{
	DMA_Channel0,
	DMA_Channel1,
	DMA_Channel2,
	DMA_Channel3,
	DMA_Channel4,
	DMA_Channel5,
	DMA_Channel6,
	DMA_Channel7
};

enum DMA_STREAM_PRIORITY
{
	DMA_LOW_PRIORITY,
	DMA_MEDIUM_PRIORITY,
	DMA_HIGH_PRIORITY,
	DMA_VERY_HIGH_PRIORITY
};

enum FLOW_CONTROLLER
{
	DMA_FLOW_CONTROLLER,
	PERIPHERAL_FLOW_CONTROLLER
};

enum DMA_BURSTS
{
	SINGLE_TRANSFER,
	INCR4,
	INCR8,
	INCR16
};

enum DMA_FIFO_THRESHOLDS
{
	FIFO_ONEFOURTH,
	FIFO_HALF,
	FIFO_THREEFOURTH,
	FIFO_FULL
};

void DMA_StreamInit(DMA_STREAM_t* _stream, uint8_t _channel, uint8_t _msize, uint8_t _psize, uint8_t _direction, uint8_t _pointer_mode, uint8_t _priority);
void DMA_SelectChannel(DMA_STREAM_t* _stream, uint8_t _channel);
void DMA_SetDataSize(DMA_STREAM_t* _stream, uint8_t _msize, uint8_t _psize);
void DMA_SetDirection(DMA_STREAM_t* _stream, uint8_t _direction);
void DMA_SetTransferMode(DMA_STREAM_t* _stream, uint8_t _pointer_mode);
void DMA_SetStreamPriority(DMA_STREAM_t* _stream, uint8_t _priority);
void DMA_SetNumberOfDataItems(DMA_STREAM_t* _stream, uint16_t _nItems);
void DMA_SetDataAddress(DMA_STREAM_t* _stream, uint32_t* _destAddr, uint32_t* _srcAddr);
void DMA_EnableStream(DMA_STREAM_t* _stream);
void DMA_DisableStream(DMA_STREAM_t* _stream);
void DMA_EnableIRQ(DMA_STREAM_t* _stream, uint8_t _IRQ);
void DMA_DisableIRQ(DMA_STREAM_t* _stream, uint8_t _IRQ);
void DMA_EnableCircularMode(DMA_STREAM_t* _stream);
void DMA_DisableCircularMode(DMA_STREAM_t* _stream);
void DMA_SelectFlowController(DMA_STREAM_t* _stream, uint8_t _flow_controller);
void DMA_ClearLIFCRFlag(DMA_PERIPHERALS_t* _dma, uint8_t _flag);
void DMA_ClearHIFCRFlag(DMA_PERIPHERALS_t* _dma, uint8_t _flag);
void DMA_SetFIFOThreshold(DMA_STREAM_t* _stream, uint8_t _fifo_th);

#endif /* STM32F411XX_DMA_H_ */
