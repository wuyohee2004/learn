/**
 *
 *  comment here
 *
 */

#include <g-bios.h>
#include <arch/arm.h>
#include <core/kermit.h>
#include <autoconf.h>


.global GTopHalfEntry
.global Hang


GTopHalfEntry:
	ldr   pc, vect_reset
	ldr   pc, vect_undef
	ldr   pc, vect_swi
	ldr   pc, vect_iabort
	ldr   pc, vect_dabort
	.word (gbios_th_end - GTopHalfEntry)
	ldr   pc, vect_irq
	ldr   pc, vect_fiq

	.word GB_MAGIC_TH

vect_reset:
	.word handle_reset
vect_undef:
	.word handle_undef
vect_swi:
	.word handle_swi
vect_iabort:
	.word handle_iabort
vect_dabort:
	.word handle_dabort
vect_irq:
	.word handle_irq
vect_fiq:
	.word handle_fiq


handle_fiq:
handle_irq:
handle_dabort:
handle_iabort:
handle_swi:
handle_undef:
handle_reset:
	msr   cpsr, #(ARM_MODE_SVC | ARM_INT_MASK)
	mov   sp, #INIT_STACK_BASE

	bl    main

Hang:
	b	 Hang

#if 0
	bl	 GtInitSoC

	bl	 GtInitUart

	ldr  r0, =banner
	bl	 UartPuts

	bl	 GtInitMemCtrl

	bl	 GtInitNand
			
BootMenu:
	ldr  r0, =msg_boot_menu
	bl	 UartPuts
	
	mov	 r6, #'1'

bm_loop:
	bl	 GtUartReadByte
	bl	 GtUartWriteByte
	
	cmp  r0, #'\n'
	beq  do_result
	cmp  r0, #'\r'
	beq  do_result
	
	mov  r6, r0
	b	 bm_loop
	
do_result:
	mov  r0, #'\n'
	bl	 GtUartWriteByte
	mov  r0, #'\r'
	bl	 GtUartWriteByte

	sub  r0, r6, #'1'
	cmp  r0, #1
	ldrls	 pc, [pc, r0, lsl #2]
	b	 __default
__switch:
	.word case_1
	.word case_2
	
case_1:
	b	NandBoot
	
case_2:
	b	SerialBoot
	
__default:
	ldr  r0, =msg_wrong_choice
	bl	 UartPuts
	b	 BootMenu

NandBoot:
	ldr r0, =GBIOS_BH_START
	ldr r1, =GBIOS_BH_OFFSET
	bl	GtNandLoad

	b	StartGbios

SerialBoot:
	ldr r0, =GBIOS_BH_START
	bl	GtSerialLoad

	b	StartGbios
	
StartGbios:
	ldr r1, =GBIOS_BH_START

	ldr r2, [r1, #4]
	ldr r3, =GB_MAGIC_BH
	cmp r2, r3
	beq launch_bh

	ldr r0, =msg_bottom_miss
	bl	UartPuts
	
launch_bh:
	ldr r0, =msg_booting
	bl	UartPuts

	mov lr, pc
	ldr pc, =GBIOS_BH_START


banner:
	.ascii "\033[2J"
	.ascii "\n\r\n\r"
	.ascii "\t+----------------------------------+\n\r"
	.ascii "\t|     Welcome to MaxWit g-bios!    |"   
	.ascii "\n\r"
	.ascii "\t|  (http://maxwit.googlecode.com)  |\n\r"
	.ascii "\t|       ["
	.ascii BUILD_TIME 
	.ascii "]        |\n\r"
	.asciz "\t+----------------------------------+\n\r"
	.align 2

msg_boot_menu:
	.ascii "\n\rLoad g-bios from:\n\r"
	.ascii "\t 1. Flash  -> SDRAM (default)\n\r"
	.ascii "\t 2. Serial -> SDRAM\n\r"
	.asciz "Pls Enter [1-2] to Boot: "
	.align 2

msg_wrong_choice:
	.asciz "Wrong Choice!, Please Try Again ...\n\r"
	.align 2

msg_bottom_miss:	
	.asciz "NO correct bottom-half was loaded!\n\r" 
	.align 2

msg_booting:	
	.asciz "Booting bottom-half ...\n\r"	
	.align 2
#endif

