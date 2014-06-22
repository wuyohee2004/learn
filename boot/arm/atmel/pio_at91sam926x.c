#include <autoconf.h>
#include <core/types.h>
#include <core/io.h>
#include <arch/at91sam926x.h>


void At91PioConfPeriA(UINT32 nPioIdx, UINT32 dwVal)
{
	UINT32 dwPioBase;

	dwPioBase = AT91SAM926X_PA_PIOA + (0x200 * nPioIdx);
	WriteLong(dwVal, dwPioBase + PIO_ASR);
	WriteLong(dwVal, dwPioBase + PIO_PDR);
}

