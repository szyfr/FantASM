;*/
;* @Date:		7/26/21
;* @Author:		Szyfr
;*/


;;=  Converts a byte to a string in hex
;;=		Input:		RCX = stringPtr
;;=					 DL = byte
;;=		Output:		N/A
;;?  I KNOW there is a much better way of doing this.
;;?  I just didn't care enough to look up the right way.
;;?
;;?  Honestly, the more I think about just HOW bad this is, the more I love it.
stringPtr			equ		rcx
byteConv			equ		dl
hex_converter:
	sub		rsp,	28h

.convert_first_4:
	xor		rax,					rax
	mov		al,						dl
	shr		al,						4

	cmp		al,						0
	je		.first_0
	cmp		al,						1
	je		.first_1
	cmp		al,						2
	je		.first_2
	cmp		al,						3
	je		.first_3
	cmp		al,						4
	je		.first_4
	cmp		al,						5
	je		.first_5
	cmp		al,						6
	je		.first_6
	cmp		al,						7
	je		.first_7
	cmp		al,						8
	je		.first_8
	cmp		al,						9
	je		.first_9
	cmp		al,						10
	je		.first_a
	cmp		al,						11
	je		.first_b
	cmp		al,						12
	je		.first_c
	cmp		al,						13
	je		.first_d
	cmp		al,						14
	je		.first_e
	cmp		al,						15
	je		.first_f

.first_0:
	mov		byte[rcx],				'0'
	jmp		.convert_last_4
.first_1:
	mov		byte[rcx],				'1'
	jmp		.convert_last_4
.first_2:
	mov		byte[rcx],				'2'
	jmp		.convert_last_4
.first_3:
	mov		byte[rcx],				'3'
	jmp		.convert_last_4
.first_4:
	mov		byte[rcx],				'4'
	jmp		.convert_last_4
.first_5:
	mov		byte[rcx],				'5'
	jmp		.convert_last_4
.first_6:
	mov		byte[rcx],				'6'
	jmp		.convert_last_4
.first_7:
	mov		byte[rcx],				'7'
	jmp		.convert_last_4
.first_8:
	mov		byte[rcx],				'8'
	jmp		.convert_last_4
.first_9:
	mov		byte[rcx],				'9'
	jmp		.convert_last_4
.first_a:
	mov		byte[rcx],				'a'
	jmp		.convert_last_4
.first_b:
	mov		byte[rcx],				'b'
	jmp		.convert_last_4
.first_c:
	mov		byte[rcx],				'c'
	jmp		.convert_last_4
.first_d:
	mov		byte[rcx],				'd'
	jmp		.convert_last_4
.first_e:
	mov		byte[rcx],				'e'
	jmp		.convert_last_4
.first_f:
	mov		byte[rcx],				'f'
	jmp		.convert_last_4

.convert_last_4:
	inc		rcx
	xor		rax,					rax
	mov		al,						dl
	shl		al,						4
	xor		ah,						ah
	shr		al,						4

	cmp		al,						0
	je		.last_0
	cmp		al,						1
	je		.last_1
	cmp		al,						2
	je		.last_2
	cmp		al,						3
	je		.last_3
	cmp		al,						4
	je		.last_4
	cmp		al,						5
	je		.last_5
	cmp		al,						6
	je		.last_6
	cmp		al,						7
	je		.last_7
	cmp		al,						8
	je		.last_8
	cmp		al,						9
	je		.last_9
	cmp		al,						10
	je		.last_a
	cmp		al,						11
	je		.last_b
	cmp		al,						12
	je		.last_c
	cmp		al,						13
	je		.last_d
	cmp		al,						14
	je		.last_e
	cmp		al,						15
	je		.last_f

.last_0:
	mov		byte[rcx],				'0'
	jmp		.exit
.last_1:
	mov		byte[rcx],				'1'
	jmp		.exit
.last_2:
	mov		byte[rcx],				'2'
	jmp		.exit
.last_3:
	mov		byte[rcx],				'3'
	jmp		.exit
.last_4:
	mov		byte[rcx],				'4'
	jmp		.exit
.last_5:
	mov		byte[rcx],				'5'
	jmp		.exit
.last_6:
	mov		byte[rcx],				'6'
	jmp		.exit
.last_7:
	mov		byte[rcx],				'7'
	jmp		.exit
.last_8:
	mov		byte[rcx],				'8'
	jmp		.exit
.last_9:
	mov		byte[rcx],				'9'
	jmp		.exit
.last_a:
	mov		byte[rcx],				'a'
	jmp		.exit
.last_b:
	mov		byte[rcx],				'b'
	jmp		.exit
.last_c:
	mov		byte[rcx],				'c'
	jmp		.exit
.last_d:
	mov		byte[rcx],				'd'
	jmp		.exit
.last_e:
	mov		byte[rcx],				'e'
	jmp		.exit
.last_f:
	mov		byte[rcx],				'f'
	jmp		.exit


.exit:
	dec		rcx
	add		rsp,	28h
	ret