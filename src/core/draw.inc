;*/
;* @Date:		7/24/21
;* @Author:		Szyfr
;*/


;;=  Draw
;;=		Input:		N/A
;;=		Output:		N/A
draw_emu:
	sub		rsp,	28h

.temp:
	call	BeginDrawing
	mov		rcx,				WHITE
	call	ClearBackground
	call	EndDrawing

.exit:
	add		rsp,	28h
	ret