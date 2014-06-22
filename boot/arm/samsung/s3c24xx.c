/**
 *
 *  comment here
 *
 */

#include <autoconf.h>
#include <arch/arm.h>
#include <core/io.h>


int GtInitSoC(void)
{
	WriteLong(0x0, WATCHDOG_BASE + WTCON);

#ifdef CONF_S3C2410
	WriteLong((0xc3 << 12) | (4 << 4) | 1, CLOCK_BASE + MPLLCON);
	WriteLong(0x3, CLOCK_BASE + DIVN);
#elif defined(CONF_S3C2440)
	WriteLong(0xffffff, CLOCK_BASE + LOCKTIME);
	WriteLong(0x7f021, CLOCK_BASE + MPLLCON);
	WriteLong(0x5, CLOCK_BASE + DIVN);
#else
	#error
#endif

	return 0;
}


static UINT32 g_vMemConf[] = {
#ifdef CONF_S3C2410
	0x2200d000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00001f4c,
	0x00000000,
	0x00000000,
	0x00018001,
	0x00018001,
	0x008404e8,
	0x00000011,
	0x00000020,
	0x00000020,
#elif defined(CONF_S3C2440)
	0x220dd000,
	0x00000700,
	0x00000700,
	0x00000700,
	0x00000700,
	0x00000700,
	0x00000700,
	0x00018009,
	0x00018009,
	0x00ac03f4,
	0x000000b2,
	0x00000030,
	0x00000030
#endif
};


// to be improved
int GtInitMemCtrl(void)
{
	__VOLATILE__ int i;
	__VOLATILE__ ULONG *p;


	p = (ULONG *)MEMCON_BASE;
	for (i = 0; i < ARRAY_ELEM_NUM(g_vMemConf); i++)
	{
		p[i] = g_vMemConf[i];
	}

	for (i = 0; i < 256; i++);

	p = (ULONG *)GBIOS_BH_START;

	*p = 0UL;
	if (*p != 0UL) return -1;

	*p = ~0UL;
	if (*p != ~0UL) return -1;

	return 0;
}

