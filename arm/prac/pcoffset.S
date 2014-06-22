	.global main
main:
	SUB R1,PC,#4
	STR PC,[R0]
	LDR R0,[R0]
	SUB R0,R0,R1
	STMFD SP!,{LR}
	BL printf
	LDMFD SP!,{PC}
