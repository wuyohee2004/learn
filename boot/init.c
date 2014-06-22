/**
 *
 *  comment here
 *
 */

#include <g-bios.h>
#include <arch/arm.h>
#include <core/kermit.h>
#include <core/types.h>
#include <tophalf.h>


static void BootMenu(void);
static void StartGbios(void);

int main(void)
{
	const char *pchBanner = "\n\n" // CLRSCREEN
		"\t+----------------------------------+\n\r"
		"\t|     Welcome to MaxWit g-bios!    |\n\r"
		"\t|  (http://maxwit.googlecode.com)  |\n\r"
		"\t|        ["   BUILD_TIME  "]       |\n\r"
		"\t+----------------------------------+\n\r";

	GtInitSoC();

	GtInitUart();

	puts(pchBanner);

	ReadID();

	GtInitMemCtrl();

	GtInitNand();

	BootMenu();

	return -1;
}


void BootMenu(void)
{
	char bPrev, bSel;
	int nCount;
	const char *pchBootMenu = "\n\r"
			"Load g-bios from (1.Flash, 2.Serial): ";


	while (1)
	{
		nCount = 0;
		bSel   = '1';

		UartPuts(pchBootMenu);

		while (1)
		{
			bPrev = GtUartReadByte();

			if (bPrev == '\n' || bPrev == '\r')
			{
				puts("");
				break;
			}

			GtUartWriteByte(bPrev);
			bSel = bPrev;
			nCount++;
		}

		if (nCount <= 1)
		{
			switch (bSel)
			{
			case '1':
				GtNandLoad();
				StartGbios();
				break;

			case '2':
				GtSerialLoad((void *)GBIOS_BH_START);
				StartGbios();
				break;

			default:
				break;
			}
		}

		puts("Wrong Choice!");
	}
}


typedef void (*BottomEntry)(void);

void StartGbios(void)
{
	BottomEntry pfBottomEntry;


	pfBottomEntry = (BottomEntry)GBIOS_BH_START;

	if (GB_MAGIC_BH != ReadLong(GBIOS_BH_START + 4))
	{
		puts("Wrong g-bios!\n");
	}


	pfBottomEntry();
}

