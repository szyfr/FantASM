;*/
;* @Date:		7/24/21
;* @Author:		Szyfr
;*/


;;=  Update
;;=		Input:		N/A
;;=		Output:		N/A
dataPtr				equ		r8
dataOffsetPtr		equ		r9
programCounter		equ		rdx

regA				equ		al
regF				equ		ah
regB				equ		bl
regC				equ		bh

regAF				equ		ax
regBC				equ		bx
regSP				equ		cx
regPC				equ		dx

nextByte			equ		r10b

op_nop				equ		00h
op_ldad				equ		0eh
op_halt				equ		10h
update_emu:
	sub		rsp,	28h

.read_next_byte:
	mov		dataOffsetPtr,			dataPtr
	add		dataOffsetPtr,			programCounter
	inc		dataOffsetPtr
	mov		nextByte,				[dataOffsetPtr]

.nop:
	cmp		nextByte,				op_nop
	jne		.ldad
	jmp		.exit

.ldad:
	cmp		nextByte,				op_ldad
	jne		.halt
	inc		dataOffsetPtr
	mov		regA,					[dataOffsetPtr]
	jmp		.exit

.halt:
	;;TODO: Halt
	cmp		nextByte,				op_halt
	jne		.stop
	jmp		.exit

.stop:

.exit:
	add		rsp,	28h
	ret