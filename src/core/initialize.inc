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

fileLocation		equ		rcx
fileBytes			equ		rdx
file				equ		rax

memoryMap			equ		r8
bootROM				equ		r9
counter				equ		rcx
byteTransfer		equ		bl
initialize_emu:
	sub		rsp,	28h

.initialize_screen:
	mov		initWidth,				200
	mov		initHeight,				400
	lea		initTitlePtr,			[title]
	call	InitWindow

	mov		targetFPS,				60
	call	SetTargetFPS

.initialize_memory_map:
	mov		mallocSize,				1000h
	call	MemAlloc
	mov		[memory_map],			mallocOutput
.initialize_boot_ROM:
	lea		fileLocation,			[boot_location]
	mov		fileBytes,				[memory_map]
	call	LoadFileData
	mov		[boot_ROM],				file

.copy_rom_data:
	mov		memoryMap,				[memory_map]
	mov		bootROM,				[boot_ROM]
	xor		counter,				counter
.loop:
	mov		byteTransfer,			byte[bootROM]
	mov		byte[memoryMap],		byteTransfer
	inc		memoryMap
	inc		bootROM
	inc		counter
	cmp		counter,				500h
	jl		.loop	

.initialize_registers:
	xor		rax,					rax
	xor		rbx,					rbx
	xor		rcx,					rcx
	xor		rdx,					rdx

.exit:
	add		rsp,	28h
	ret