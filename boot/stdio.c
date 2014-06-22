#include <tophalf.h>

void UartPuts(const char *pStr)
{
	const char *p;

	for (p = pStr; *p; p++)
		GtUartWriteByte(*p);
}


int puts(const char *p)
{
	for (; *p; p++)
	{
		GtUartWriteByte(*p);

		if (*p == '\n')
			GtUartWriteByte('\r');
	}

	GtUartWriteByte('\n');	
	GtUartWriteByte('\r');

	return 0;
}

void U8ToStr(UINT32 val, char str[])
{
	int i, j;

	for (i = 4, j = 0; j < 2; i -= 4, j++)
	{
		str[j] = (val >> i) & 0xf;

		if (str[j] > 9)
			str[j] += 'A' - 10;
		else
			str[j] += '0';
	}

	str[j] = '\0';
}

void U16ToStr(UINT32 val, char str[])
{
	int i, j;

	for (i = 12; (i >= 0) && (((val >> i) & 0xf) == 0); i -= 4);

	for (j = 0; i >= 0; i -= 4, j++)
	{
		str[j] = (val >> i) & 0xf;

		if (str[j] > 9)
			str[j] += 'A' - 10;
		else
			str[j] += '0';
	}

	str[j] = '\0';
}

void U32ToStr(UINT32 val, char str[])
{
	int i, j;

	for (i = 28, j = 0; j < 8; i -= 4, j++)
	{
		str[j] = (val >> i) & 0xf;

		if (str[j] > 9)
			str[j] += 'A' - 10;
		else
			str[j] += '0';
	}

	str[j] = '\0';
}

