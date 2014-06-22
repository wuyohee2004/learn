	.global main
main:
	STMFD SP!,{LR}
	LDR r0,pstr
	BL printf
	LDMFD SP!,{PC}
pstr:
	.word str
str:
	.ascii "hello,world!\n\0"
