/*
 * STM32F411xx_DMA.c
 *
 * Created on: 12-Nov-2021
 * Author: Devashish Lahariya
*/

#include "STM32F411xx_DMA.h"

void DMA_StreamInit(DMA_STREAM_t* _stream, uint8_t _channel, uint8_t _msize, uint8_t _psize, uint8_t _direction, uint8_t _pointer_mode, uint8_t _priority)
{
	_stream -> CR &= ~(7 << DMA_CHSEL);
	_stream -> CR |= (_channel << DMA_CHSEL);

	_stream -> CR &= ~(3 << DMA_MSIZE);
	_stream -> CR &= ~(3 << DMA_PSIZE);

	if(_msize > DATA_8_BIT)
	{
		_stream -> CR |= (_msize << DMA_MSIZE);
	}
	if(_psize > DATA_8_BIT)
	{
		_stream -> CR |= (_psize << DMA_PSIZE);
	}
	_stream -> CR &= ~(3 << DMA_DIR);

	if(_direction > PERI_TO_MEM)
	{
		_stream -> CR |= (_direction << DMA_DIR);
	}
	_stream -> CR &= ~(1 << DMA_PINC);
	_stream -> CR &= ~(1 << DMA_MINC);

	uint32_t scr = _stream -> CR;

	switch(_pointer_mode)
	{
	case FIXED_MODE:
		_stream -> CR &= ~(1 << DMA_PINC);
		_stream -> CR &= ~(1 << DMA_MINC);
		break;

	case SOURCE_AUTO_INC:
		if((scr & (1 << DMA_DIR)))					//MEMORY-TO-PERIPHERAL
		{
			_stream -> CR &= ~(1 << DMA_PINC);
			_stream -> CR |=  (1 << DMA_MINC);
		}
		else										//PERIPHERAL-TO-MEMORY & MEMORY-TO-MEMORY
		{
			_stream -> CR |=  (1 << DMA_PINC);
			_stream -> CR &= ~(1 << DMA_MINC);
		}
		break;

	case DEST_AUTO_INC:
		if((scr & (1 << DMA_DIR)))					//MEMORY-TO-PERIPHERAL
		{
			_stream -> CR |=  (1 << DMA_PINC);
			_stream -> CR &= ~(1 << DMA_MINC);
		}
		else										//PERIPHERAL-TO-MEMORY & MEMORY-TO-MEMORY
		{
			_stream -> CR &= ~(1 << DMA_PINC);
			_stream -> CR |=  (1 << DMA_MINC);
		}
		break;

	case SD_AUTO_INC:
		_stream -> CR |=  (1 << DMA_PINC);
		_stream -> CR |=  (1 << DMA_MINC);
		break;
	}
	_stream -> CR &= ~(3 << DMA_PL);

	if(_priority > DMA_LOW_PRIORITY)
	{
		_stream -> CR |= (_priority << DMA_PL);
	}
}

void DMA_SelectChannel(DMA_STREAM_t* _stream, uint8_t _channel)
{
	_stream -> CR &= ~(7 << DMA_CHSEL);
	_stream -> CR |= (_channel << DMA_CHSEL);
}

void DMA_SetDataSize(DMA_STREAM_t* _stream, uint8_t _msize, uint8_t _psize)
{
	_stream -> CR &= ~(3 << DMA_MSIZE);
	_stream -> CR &= ~(3 << DMA_PSIZE);

	if(_msize > DATA_8_BIT)
	{
		_stream -> CR |= (_msize << DMA_MSIZE);
	}
	if(_psize > DATA_8_BIT)
	{
		_stream -> CR |= (_psize << DMA_PSIZE);
	}
}

void DMA_SetDirection(DMA_STREAM_t* _stream, uint8_t _direction)
{
	_stream -> CR &= ~(3 << DMA_DIR);

	if(_direction > PERI_TO_MEM)
	{
		_stream -> CR |= (_direction << DMA_DIR);
	}
}

void DMA_SetTransferMode(DMA_STREAM_t* _stream, uint8_t _pointer_mode)
{
	_stream -> CR &= ~(3 << _pointer_mode);

	switch(_pointer_mode)
	{
	case FIXED_MODE:
		_stream -> CR &= ~(1 << DMA_PINC);
		_stream -> CR &= ~(1 << DMA_MINC);
		break;

	case SOURCE_AUTO_INC:
		_stream -> CR &= ~(1 << DMA_PINC);
		_stream -> CR |=  (1 << DMA_MINC);
		break;

	case DEST_AUTO_INC:
		_stream -> CR |=  (1 << DMA_PINC);
		_stream -> CR &= ~(1 << DMA_MINC);
		break;

	case SD_AUTO_INC:
		_stream -> CR |=  (1 << DMA_PINC);
		_stream -> CR |=  (1 << DMA_MINC);
		break;
	}
}

void DMA_SetStreamPriority(DMA_STREAM_t* _stream, uint8_t _priority)
{
	_stream -> CR &= ~(3 << DMA_PL);
	_stream -> CR |= (_priority << DMA_PL);
}

void DMA_SetNumberOfDataItems(DMA_STREAM_t* _stream, uint16_t _nItems)
{
	_stream -> NDTR = _nItems;
}

void DMA_SetDataAddress(DMA_STREAM_t* _stream, uint32_t* _destAddr, uint32_t* _srcAddr)
{
	uint32_t scr = _stream -> CR;

	if(scr & (1 << (DMA_DIR)))
	{
		_stream -> M0AR = (uint32_t)_srcAddr;
		_stream -> PAR  = (uint32_t)_destAddr;
	}
	else
	{
		_stream -> PAR  = (uint32_t)_srcAddr;
		_stream -> M0AR = (uint32_t)_destAddr;
	}
}

void DMA_EnableStream(DMA_STREAM_t* _stream)
{
	_stream -> CR |= (1 << DMA_EN);
}

void DMA_DisableStream(DMA_STREAM_t* _stream)
{
	_stream -> CR &= ~(1 << DMA_EN);
}

void DMA_EnableIRQ(DMA_STREAM_t* _stream, uint8_t _IRQ)
{
	_stream -> CR |= (1 << _IRQ);
}

void DMA_DisableIRQ(DMA_STREAM_t* _stream, uint8_t _IRQ)
{
	_stream -> CR &= ~(1 << _IRQ);
}

void DMA_EnableDoubleBufferModeMTP(DMA_STREAM_t* _stream, uint32_t* _destAddr, uint32_t* _srcAddr1, uint32_t* _srcAddr2, uint8_t _CT)
{
	_stream -> M0AR = *_srcAddr1;
	_stream -> M1AR = *_srcAddr2;
	_stream -> PAR  = *_destAddr;

	if(_CT == 1)
	{
		_stream -> CR |= (1 << DMA_CT);
	}
	else
	{
		_stream -> CR &= ~(1 << DMA_CT);
	}
	_stream -> CR |= (1 << DMA_DBM);
}

void DMA_EnableCircularMode(DMA_STREAM_t* _stream)
{
	_stream -> CR |= (1 << DMA_CIRC);
}

void DMA_DisableCircularMode(DMA_STREAM_t* _stream)
{
	_stream -> CR &= ~(1 << DMA_CIRC);
}

void DMA_ClearLIFCRFlag(DMA_PERIPHERALS_t* _dma, uint8_t _flag)
{
	_dma -> LIFCR |= (1 << _flag);
}

void DMA_ClearHIFCRFlag(DMA_PERIPHERALS_t* _dma, uint8_t _flag)
{
	_dma -> HIFCR |= (1 << _flag);
}

void DMA_SelectFlowController(DMA_STREAM_t* _stream, uint8_t _flow_controller)
{
	if(_flow_controller == DMA_FLOW_CONTROLLER)
	{
		_stream -> CR &= ~(1 << DMA_PFCTRL);
	}
	else
	{
		_stream -> CR |= (1 << DMA_PFCTRL);
	}
}

void DMA_SetFIFOThreshold(DMA_STREAM_t* _stream, uint8_t _fifo_th)
{
	_stream -> FCR &= ~(3 << DMA_FTH);

	if(_fifo_th > FIFO_ONEFOURTH)
	{
		_stream -> FCR |= (_fifo_th << DMA_FTH);
	}
}
