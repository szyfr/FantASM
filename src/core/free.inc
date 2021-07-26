;*/
;* @Date:		7/24/21
;* @Author:		Szyfr
;*/


;;=  Frees emulator
;;=		Input:		N/A
;;=		Output:		N/A
freePtr				equ		rcx
free_emu:
	sub		rsp,	28h

.free_rom:
	mov		freePtr,				[memory_map]
	call	MemFree

.close_window:
	call	CloseWindow

.exit:
	add		rsp,	28h
	ret