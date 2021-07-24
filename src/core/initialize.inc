;*/
;* @Date:		7/24/21
;* @Author:		Szyfr
;*/


;;=  Initializes emulator
;;=		Input:		N/A
;;=		Output:		N/A
initWidth			equ		ecx
initHeight			equ		edx
initTitlePtr		equ		r8

targetFPS			equ		rcx

mallocSize			equ		rcx
mallocOutput		equ		rax
initialize_emu:
	sub		rsp,	28h

.initialize_screen:
	mov		initWidth,				200
	mov		initHeight,				400
	lea		initTitlePtr,			[title]
	call	InitWindow

	mov		targetFPS,				60
	call	SetTargetFPS

.initialize_rom:
	;;TODO: Temporary until file loading is implemented
	mov		mallocSize,				100
	call	MemAlloc
	mov		[rom],					mallocOutput

.initialize_registers:
	xor		rax,					rax
	xor		rbx,					rbx
	xor		rcx,					rcx
	xor		rdx,					rdx
	mov		r8,						[rom]

.exit:
	add		rsp,	28h
	ret