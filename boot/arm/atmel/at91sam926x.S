/**
 *
 *  comment here
 *
 */

#include <arch/arm.h>
#include <autoconf.h>
#include <core/uart.h>

.global  GtInitSoC
.global  GtInitUart
.global  GtInitMemCtrl
.global  GtInitNand

.global  GtUartReadByte
.global  GtUartWriteByte


GtInitSoC:
	stmfd sp!, {lr}

	// disable watchdog
	ldr  r0, =AT91SAM926X_PA_WDTC
	mov  r1, #(0x1 << 15)
	str  r1, [r0, #WDTC_WDMR]

	//
	ldr  r0,  =AT91SAM926X_PA_PMC

	mvn  r1, #0
	str  r1, [r0, #PMC_IDR]

	ldr  r1, =0x2060BF09
	str  r1, [r0, #PMC_PLLAR]
L1:
	ldr  r1, [r0, #PMC_SR]
	tst  r1, #0x2
	beq  L1

	ldr  r1, =0x102
	str  r1, [r0, #PMC_MCKR]
L2:
	ldr  r1, [r0, #PMC_SR]
	tst  r1, #0x8
	beq  L2

	ldmfd sp!, {pc}


GtInitUart:
	stmfd sp!, {lr}

#ifdef CONF_AT91SAM9261
	mov  r0, #PIOA
	mov  r1, #(3 << 9)
	bl   At91PioConfPeriA
#elif defined(CONF_AT91SAM9263)
	mov  r0, #PIOC
	mov  r1, #(3 << 30)
//	mov  r2, #0
	bl	 At91PioConfPeriA
#endif

	ldr  r0, =AT91SAM926X_PA_DBGU

	mvn  r1, #0
	str  r1, [r0, #US_IDR]

	mov  r1, #0x10c
	str  r1, [r0, #US_CR]

	mov  r1, #0x50
	str  r1, [r0, #US_CR]

	ldr  r1, =(MASTER_CLOCK_VALUE / (BR115200 * 16))
	str  r1, [r0, #US_BRGR]

	mov  r1, #0x800
	str  r1, [r0, #US_MR]

	ldr  r1, =0x101
	str  r1, [r0, #US_PTCR]

	ldmfd sp!, {pc}


GtInitMemCtrl:
	stmfd sp!, {lr}

#ifdef CONF_AT91SAM9261
	ldr   r0, =AT91SAM926X_PA_MATRIX
	ldr   r1, =0x13a
	str   r1, [r0, #MATRIX_EBICSA]

	mov   r0, #PIOC
	ldr   r1, =0xffff0000
	bl 	  At91PioConfPeriA
#elif defined(CONF_AT91SAM9263)
	ldr  r0, =AT91SAM926X_PA_MATRIX
	ldr  r1, [r0, #MATRIX_EBI0CSA]
	orr  r1, r1, #(0x1 << 16)
	orr  r1, r1, #(0x1 << 1)
	str  r1, [r0, #MATRIX_EBI0CSA]

	mov   r0, #PIOD
	ldr   r1, =0xffff0000
	bl	  At91PioConfPeriA
#endif

	ldr   r0, =AT91SAM926X_PA_SDRAMC
	mov   r1, #SDRAM_BASE

	ldr   r2, =SDRAM_CONF_RATE_100
	str   r2, [r0, #SDRAMC_CR]

	mov   r2, #0x0
	str   r2, [r0, #SDRAMC_MDR]
	mov   r2, #0x10000
L3:
	subs  r2, r2, #1
	bge   L3

#if 1
	mov   r2, #0x1
	str   r2, [r0, #SDRAMC_MR]
	mov   r2, #0x0
	str   r2, [r1]
#endif

	mov   r2, #0x2
	str   r2, [r0, #SDRAMC_MR]
	mov   r2, #0x0
	str   r2, [r1]

	mov   r3, #8
L4:
	mov   r2, #0x4
	str   r2, [r0, #SDRAMC_MR]
	mov   r2, #0x0
	str   r2, [r1]
	subs  r3, r3, #1
	bge   L4

	mov   r2, #0x3		
	str   r2, [r0, #SDRAMC_MR]
	mov   r2, #0x0
	str   r2, [r1]

	mov   r2, #0x0
	str   r2, [r0, #SDRAMC_MR]
	mov   r2, #0x0
	str   r2, [r1]

	ldr   r2, =(MASTER_CLOCK_VALUE * 7 / 1000000)
	str   r2, [r0, #SDRAMC_TR]

	mov   r2, #0x0
	str   r2, [r1]
	ldr   r3, [r1]
	cmp   r3, r2
	bne   Hang
	mvn   r2, #0x0
	str   r2, [r1]
	ldr   r3, [r1]
	bne   Hang

	ldmfd sp!, {pc}

#ifdef CONF_AT91SAM9261
At91NandIsReady:
	ldr   r0, =AT91SAM926X_PA_PIOC
	ldr   r0, [r0, #PIO_PDSR]
	and   r0, r0, #PIO_NAND_RDY
	mov   pc, lr

GtInitNand:
	stmfd sp!, {r4, lr}

	ldr  r0, =AT91SAM926X_PA_MATRIX
	ldr  r1, [r0, #MATRIX_EBICSA]
	orr  r1, r1, #(1 << 3)
	str  r1, [r0, #MATRIX_EBICSA]

	ldr  r0, =AT91SAM926X_PA_SMC

	mov  r1, #0
	str  r1, [r0, #SMC_SETUP(3)]

	ldr  r1, =(4 | (6 << 8) | (3 << 16) | (5 << 24))
	str  r1, [r0, #SMC_PULSE(3)]

	ldr  r1, =(6 | (5 << 16))
	str  r1, [r0, #SMC_CYCLE(3)]

	ldr  r1, =(1 | (1 << 1) | (1 << 16))
	str  r1, [r0, #SMC_MODE(3)]

	ldr  r0, =AT91SAM926X_PA_PMC
	mov  r1, #(1 << 4)
	str  r1, [r0, #PMC_PCER]

	// fixme
	ldr  r0, =AT91SAM926X_PA_PIOC

	mov  r1, #PIO_NAND_RDY
	str  r1, [r0, #PIO_PER]
	str  r1, [r0, #PIO_ODR]
	str  r1, [r0, #PIO_PUER]

	mov  r1, #3
	str  r1, [r0, #PIO_ASR]
	str  r1, [r0, #PIO_PDR]

	mov  r1, #PIO_NAND_CE
	str  r1, [r0, #PIO_PER]
	str  r1, [r0, #PIO_OER]
	str  r1, [r0, #PIO_CODR]

	mov  r4, #AT91SAM926X_PA_NAND
	add  r0, r4, #NAND_CMMD
	add  r1, r4, #NAND_ADDR
	add  r2, r4, #NAND_DATA
	ldr  r3, =At91NandIsReady
	bl   GtNandDriverInit

	ldmfd sp!, {r4, pc}

#elif defined(CONF_AT91SAM9263)
At91NandIsReady:
	stmfd sp!, {lr}
	ldr   r0, =AT91SAM926X_PA_PIOA
	ldr   r0, [r0, #PIO_PDSR]
	and   r0, r0, #PIO_NAND_RDY
	ldmfd sp!, {pc}

GtInitNand:
	stmfd sp!, {r4, lr}

	ldr  r0, =AT91SAM926X_PA_MATRIX
	ldr  r1, [r0, #MATRIX_EBI0CSA]
	orr  r1, r1, #(0x1 << 3)
	str  r1, [r0, #MATRIX_EBI0CSA]

	ldr  r0, =AT91SAM926X_PA_SMC

	mov  r1, #0
	str  r1, [r0, #SMC_SETUP(3)]

	ldr  r1, =(4 | (6 << 8) | (3 << 16) | (5 << 24))
	str  r1, [r0, #SMC_PULSE(3)]

	ldr  r1, =(6 | (5 << 16))
	str  r1, [r0, #SMC_CYCLE(3)]

	ldr  r1, =(1 | (1 << 1) | (1 << 16))
	str  r1, [r0, #SMC_MODE(3)]

	ldr  r0, =AT91SAM926X_PA_PMC
	mov  r1, #(0x1 << 2)
	str  r1, [r0, #PMC_PCER]

	ldr  r0, =AT91SAM926X_PA_PIOA
	mov  r1, #PIO_NAND_RDY
	str  r1, [r0, #PIO_PER]
	str  r1, [r0, #PIO_ODR]
	str  r1, [r0, #PIO_PUER]

	ldr  r0, =AT91SAM926X_PA_PIOD
	mov  r1, #PIO_NAND_CE
	str  r1, [r0, #PIO_PER]
	str  r1, [r0, #PIO_OER]
	str  r1, [r0, #PIO_CODR]

	ldr  r0, =AT91SAM926X_HECC0_MR
	mov  r1, #0x2
	str  r1, [r0]

	mov  r4, #AT91SAM926X_PA_NAND
	add  r0, r4, #NAND_CMMD
	add  r1, r4, #NAND_ADDR
	add  r2, r4, #NAND_DATA
	ldr  r3, =At91NandIsReady
	bl   GtNandDriverInit

	ldmfd sp!, {r4, pc}
#endif


GtUartReadByte:
	stmfd sp!, {lr}
	ldr  r1, =AT91SAM926X_PA_DBGU
rx_rdy:
	ldr  r2, [r1, #US_CSR]
	tst  r2, #1
	beq  rx_rdy
	ldrb r0, [r1, #US_RHR]
	ldmfd sp!, {pc}


GtUartWriteByte:
	stmfd sp!, {lr}
	ldr  r1, =AT91SAM926X_PA_DBGU
tx_rdy:
	ldr  r2, [r1, #US_CSR]
	tst  r2, #2
	beq  tx_rdy
	strb r0, [r1, #US_THR]
	ldmfd sp!, {pc}

