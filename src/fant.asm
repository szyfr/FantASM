;*/
;* @Date:		7/24/21
;* @Author:		Szyfr
;*/


include 'constants.inc'

;;=  Windows
format MS64 COFF

section '.text' code readable executable
public start as 'WinMain'


;;=  Main function
closeOutput			equ		al
start:
	sub		rsp,	8
	sub		rsp,	$100
.init:
	call	initialize_emu
.loop:
	call	update_emu
	call	draw_emu
	
	call	WindowShouldClose
	cmp		closeOutput,			true
	jne		.loop
.exit:
	call	free_emu	
	ret


include 'core\initialize.inc'
include 'core\update.inc'
include 'core\draw.inc'
include 'core\free.inc'

include 'debugging\hex_string.inc'

include 'data.inc'
include 'imports.inc'