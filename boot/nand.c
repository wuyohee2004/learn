#include <autoconf.h>
#include <tophalf.h>
#include <core/types.h>
#include <flash/nand_cmd.h>
#include <core/io.h>


//
static volatile struct
{
	UINT32 dwCmmdPort;
	UINT32 dwAddrPort;
	UINT32 dwDataPort;

	UINT32 nWriteSize;
	UINT32 nBlockSize;

	READY_FUNC IsReady;
} gNandFlash;


static const UINT8 gSpNandIds[] = {	
	0x33, 0x35, 0x36, 0x39, 0x43, 0x45,0x46, 0x49, 0x53, 0x55, 
	0x56, 0x59, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x78, 0x79
};



// Basic operations
static __INLINE__ void NandWriteCmmd(UINT32 bCmmd)
{
	WriteByte(bCmmd, gNandFlash.dwCmmdPort);	
}

static __INLINE__ void NandWriteAddr(UINT8 bAddr)
{
	WriteByte(bAddr, gNandFlash.dwAddrPort);
}

static __INLINE__ BYTE NandReadByte(void)
{
	return ReadByte(gNandFlash.dwDataPort);
}

static int IsLargePage()
{
	return gNandFlash.nWriteSize >= KB(1);
}

#define TIMEOUT_COUNT  (1 << 14)

static int NandWaitReady(void)
{
	volatile int i = 0;


	if (gNandFlash.IsReady)
	{
		while (i < TIMEOUT_COUNT)
		{
			if (gNandFlash.IsReady())
				return i;
			i++;
		}

		puts("Nand Timeout!");
	}
	else
	{
		while (i < TIMEOUT_COUNT)
			i++;
	}

	return i;
}


static int IsPower2(UINT32 n)
{
	return (n & (n - 1)) == 0;
}


static void NandCmd(UINT32 nCmd, int nPageIndex, int nPageOffset)
{
	NandWriteCmmd(nCmd);

	if (nPageOffset != -1)
	{
		NandWriteAddr(nPageOffset & 0xff);

		if (IsLargePage())
			NandWriteAddr((nPageOffset >> 8) & 0xff);
	}

	if (nPageIndex != -1)
	{
		NandWriteAddr(nPageIndex & 0xff);
		NandWriteAddr((nPageIndex >> 8) & 0xff);
		
		// if ((nPageIndex >> 16) & 0xff)	 // fixme
			NandWriteAddr((nPageIndex >> 16) & 0xff);
	}

	switch (nCmd)
	{
	case NAND_CMMD_READ0:
		if (IsLargePage())
			NandWriteCmmd(NAND_CMMD_READSTART);
		break;

	default:
		break;
	}

	NandWaitReady();
}


int GtNandDriverInit(UINT32 dwCmmd, UINT32 dwAddr, UINT32 dwData, READY_FUNC NandIsReady)
{
	int i;
	UINT8  bDevID, bVenID, bExtID;
	char info[4];
	int nFront, nEnd;


	gNandFlash.dwCmmdPort = dwCmmd;
	gNandFlash.dwAddrPort = dwAddr;
	gNandFlash.dwDataPort = dwData;

	gNandFlash.IsReady = NandIsReady;

	//
	NandWaitReady();

	NandCmd(NAND_CMMD_READID, -1, 0);
	bVenID = NandReadByte();
	bDevID = NandReadByte();

	if (bDevID == 0)
	{
		puts("NAND not found!");
		return -1;
	}

	// fixme: replace with printf
	UartPuts("NAND = 0x");
	U8ToStr(bVenID, info);
	UartPuts(info);

	UartPuts(":0x");
	U8ToStr(bDevID, info); 
	UartPuts(info);

	nFront = 0;
	nEnd = ARRAY_ELEM_NUM(gSpNandIds);

	while (nFront <= nEnd)
	{
		int nMid = (nFront + nEnd) / 2;

		if (gSpNandIds[nMid] == bDevID)
		{
			gNandFlash.nWriteSize = 512;
			gNandFlash.nBlockSize = KB(16);

			goto L1;
		}			

		if (bDevID < gSpNandIds[nMid])
			nEnd = nMid -1;
		else
			nFront = nMid + 1;
	}

	bExtID = NandReadByte();
	bExtID = NandReadByte();

	gNandFlash.nWriteSize = KB(1) << (bExtID & 0x3);
	gNandFlash.nBlockSize = KB(64) << ((bExtID >> 4) & 0x03);

L1:
	if (IsPower2(gNandFlash.nWriteSize) && IsPower2(gNandFlash.nBlockSize))
		return 0;

	return -1;
}


static UINT8 *NandReadPage(UINT32 dwPageIndex, UINT8 *pBuff)
{
	UINT32 nCurLen;


	NandCmd(NAND_CMMD_READ0, dwPageIndex, 0);

	for (nCurLen = 0; nCurLen < gNandFlash.nWriteSize; nCurLen++, pBuff++)
		*pBuff = NandReadByte();

	return pBuff;
}


int GtNandLoad(void)
{
	int i;
	UINT8 *pBuff = (UINT8 *)GBIOS_BH_START;
	UINT32 nStartPage, nTotLen;
	UINT32 nWriteShift, nBlockShift;


	if (0 == gNandFlash.nBlockSize)
	{
		puts("NAND not initialized!");
		return -1;
	}

	for (i = 0; i < 32; i++)
	{
		if ((1 << i) == gNandFlash.nWriteSize)
			nWriteShift = i;

		if ((1 << i) == gNandFlash.nBlockSize)
			nBlockShift = i;
	}

#if 0
	printf("page size = 0x%x, block size = 0x%x\n",
		gNandFlash.nWriteSize, gNandFlash.nBlockSize);
#endif

	// do load now!
	nStartPage = GBIOS_BH_OFFSET << (nBlockShift - nWriteShift);

	pBuff = NandReadPage(nStartPage, pBuff);

	nTotLen = *((UINT32 *)GBIOS_BH_START + 2);
	if (nTotLen > MAX_BH_LEN)
		return -1;

	nTotLen += gNandFlash.nWriteSize - 1;

	i = nStartPage + 1;
	while (i < nStartPage + (nTotLen >> nWriteShift))
	{
		pBuff = NandReadPage(i, pBuff);
		i++;
	}

	return 0;
}

