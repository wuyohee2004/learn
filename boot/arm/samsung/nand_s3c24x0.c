
#include <arch/arm.h>
#include <autoconf.h>
#include <core/types.h>
#include <core/io.h>
#include <tophalf.h>
#include <flash/nand_cmd.h>


static int S3c24x0NandIsReady(void)
{
	return ReadByte(NAND_CTRL_BASE + NF_STAT) & 0x1;
}


int GtInitNand(void)
{
#ifdef CONF_S3C2410
	WriteShort(0x9333, NAND_CTRL_BASE + NF_CONF);
#elif defined(CONF_S3C2440)
	WriteShort(0x2440, NAND_CTRL_BASE + NF_CONF);
	WriteShort(0x1, NAND_CTRL_BASE + NF_CONT);
#endif

	GtNandDriverInit(NAND_CTRL_BASE + NF_CMMD,
				NAND_CTRL_BASE + NF_ADDR,
				NAND_CTRL_BASE + NF_DATA,
				S3c24x0NandIsReady
				);

	return 0;
}

