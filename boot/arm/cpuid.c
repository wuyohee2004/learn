#include <core/types.h>
#include <tophalf.h>
#include <core/uart.h>
#include <autoconf.h>

void ReadID(void)
{
	UINT32 nId, val;
	char str[7];
	char *vArch[] = {"4", "4T","5", "5T", "5TE", "5TEJ"};

	asm __VOLATILE__ ("mrc  p15, 0, %0, c0, c0, 0"
					: "=r"(nId)
					:
					);

	val = (nId >> 24) & 0xff;

	UartPuts("ARCH = ARM v");

	val = (nId >> 16) & 0xf;

	puts(vArch[val - 1]);

	val = (nId >> 4) & 0xfff;

	UartPuts("CPU  = ARM");

	U16ToStr(val, str);

	puts(str);

	puts("PLAT = " CONF_PLAT_NAME);
}

