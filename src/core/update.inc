;*/
;* @Date:		7/24/21
;* @Author:		Szyfr
;*/


;;=  Update
;;=		Input:		N/A
;;=		Output:		N/A
key					equ		rcx
keyResult			equ		al

memoryMap			equ		r8
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
op_ldbd				equ		1eh
update_emu:
	sub		rsp,	28h

.test_controls:
	mov		key,					KEY_P
	call	IsKeyDown
	cmp		keyResult,				1
	jne		.exit

.load_registers:
	mov		regAF,					[r_af]
	mov		regBC,					[r_bc]
	mov		regSP,					[r_sp]
	mov		regPC,					[r_pc]

.read_next_byte:
	mov		regPC,					[r_pc]
	mov		dataOffsetPtr,			[memory_map]
	add		dataOffsetPtr,			programCounter
	mov		nextByte,				[dataOffsetPtr]

.nop:
	cmp		nextByte,				op_nop
	jne		.ldad
	inc		programCounter

	jmp		.debug_exit

.ldad:
	cmp		nextByte,				op_ldad
	jne		.halt
	add		regPC,					2

	inc		dataOffsetPtr
	mov		regA,					[dataOffsetPtr]

	jmp		.debug_exit

.halt:
	cmp		nextByte,				op_halt
	jne		.ldbd

	jmp		.debug_exit

.ldbd:
	cmp		nextByte,				op_ldbd
	jne		.stop
	add		regPC,					2

	inc		dataOffsetPtr
	mov		regB,					[dataOffsetPtr]

	jmp		.debug_exit

.stop:

.error:
	lea		rcx,					[error_pc]
	add		rcx,					2
	call	hex_converter

	lea		rcx,					[error_pc]
	shr		dx,						8
	call	hex_converter

	lea		rcx,					[error_text]
	xor		rdx,					rdx
	mov		dl,						nextByte
	call	hex_converter

	call	printf

	mov		regPC,					[r_pc]
	inc		regPC

.debug_exit:
;	int3
.save_registers:
	mov		[r_af],					regAF
	mov		[r_bc],					regBC
	mov		[r_sp],					regSP
	mov		[r_pc],					regPC
.exit:
	add		rsp,	28h
	ret