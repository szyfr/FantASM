;*/
;* @Date:		7/24/21
;* @Author:		Szyfr
;*/


;;=  Draw
;;=		Input:		N/A
;;=		Output:		N/A
draw_emu:
	sub		rsp,	28h
	
	push	rax
	push	rbx
	push	rcx
	push	rdx

.temp:
	call	BeginDrawing
	mov		rcx,				WHITE
	call	ClearBackground
	call	EndDrawing

.exit:
	pop		rdx
	pop		rcx
	pop		rbx
	pop		rax

	add		rsp,	28h
	ret