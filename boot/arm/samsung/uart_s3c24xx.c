/**
 *
 *  comment here
 *
 */

#include <arch/arm.h>
#include <autoconf.h>
#include <core/types.h>
#include <core/io.h>
#include <core/uart.h>

static __INLINE__ void S3c24xxUartInitOne(UINT32 nIdx)
{
#define UARTn_BASE (UART0_BASE + nIdx * 0x4000)

	WriteLong(0x3, UARTn_BASE + ULCON);
	WriteLong(0x245, UARTn_BASE + UCON);

#ifdef UART_ENABLE_FIFO
	WriteLong(1, UARTn_BASE + UFCON);
#else
	WriteLong(0, UARTn_BASE +UFCON);
#endif

	// fixme
#define BRDIV ((50625000 / (BR115200 * 16)) - 1)
#if 0
	WriteLong(50000000, UARTn_BASE + UBRDIV);
#else
	WriteLong(BRDIV, UARTn_BASE + UBRDIV);
#endif

	{
		int i;
		for (i = 0; i < 255; i++);
	}
}


static __INLINE__ void InitGpio(void)
{
	WriteLong(0x16faaa, GPIO_BASE + GPH_CON);
	WriteLong(0x7ff, GPIO_BASE + GPH_UP);
}


int GtInitUart(void)
{
	UINT32 n;

	InitGpio();

	for (n = 0; n < UART_NUM; n++)
	{
		S3c24xxUartInitOne(n);
	}

	return 0;
}


UINT8 GtUartReadByte(void)
{
#ifdef UART_ENABLE_FIFO
	while (!(ReadLong(CURR_UART_BASE + UFSTAT) & 0xf));
#else
	while (!(ReadLong(CURR_UART_BASE + UTRSTAT) & 0x1));
#endif

	return ReadByte(CURR_UART_BASE + URX);
}


void GtUartWriteByte(UINT8 bData)
{
#ifdef UART_ENABLE_FIFO
	while (ReadLong(CURR_UART_BASE + UFSTAT)& 0x200);
#else
	while (!(ReadLong(CURR_UART_BASE + UTRSTAT)& 0x2));
#endif

	WriteByte(bData, CURR_UART_BASE + UTX);
}
