;*/
;* @Date:		7/24/21
;* @Author:		Szyfr
;*/


;;=  Windows
section '.data' readable writeable

	;;=  Program information
	title				db		'RETro', 10, 0

	;;=  Memory heaps
	rom					dq		0