	.global max	
max:
	ADD R3,R0,R1,LSL #2
	LDR R2,[R0],#4
loop:
	LDR R4,[R0],#4
	CMP R4,R2
	MOVHI R2,R4
	CMP R0,R3
	BLO loop
	MOV R0,R2
	MOV PC,LR
	
	

	
