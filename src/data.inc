;*/
;* @Date:		7/24/21
;* @Author:		Szyfr
;*/


;;=  Windows
section '.data' readable writeable

	;;=  Program information
	title				db		'RETro', 10, 0

	r_af				dw		0
	r_bc				dw		0
	r_sp				dw		0
	r_pc				dw		0

	;;=  Debug information
	nop_text			db		'nop ',0
	ldad_text			db		'ldad ',0
	error_text			db		'   - ERROR: Unknown opcode at $'
	error_pc			db		'  ',10,0

	;;=  Memory heaps
	memory_map			dq		0
	boot_ROM			dq		0
	current_ROM			dq		0

	;;=  File directory
	boot_location		db		'data/boot.bin',0