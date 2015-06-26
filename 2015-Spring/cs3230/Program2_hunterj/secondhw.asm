; CS3230 CAOS
; file: secondhw.asm
; John W Hunter

; To create executable :
; nasm -f elf secondhw.asm
; gcc -m32 secondhw.o driver.c asm_io.o
; ./a.exe or ./a.out

%include "asm_io.inc"

; initialized data is put in the .data segment
segment .data
	out1 db "Enter the number of lockers: ", 0
	out2 db "The number of lockers open: ", 0
	
; uninitialized data is put in the .bss segment
segment .bss
	numLock resd 1
	curLock resd 1
	openCount resd 1
	curStu resd 1
	numDiv resd 1
	
; code is put in the .text segment
segment .text
   global  _asm_main
   _asm_main:
      ; setup routine
      enter 0, 0 
      pusha
      ; end setup
      
      ; main program functionality
      
      call print_nl
		mov eax, out1
		call print_string
		call read_int
		mov [numLock], eax
		mov eax, 0
		mov [openCount], eax
		mov ecx, [numLock]
		lockerloop:
			mov eax, 0
			mov [numDiv], eax
			mov [curLock], ecx
			mov [curStu], ecx
			studentloop:
				mov [curStu], ecx
				mov eax, [curLock]
				cdq
				mov ebx, [curStu]
				div ebx
				cmp edx, 0
				jne continue1
				mov eax, [numDiv]
				add eax, 1
				mov [numDiv], eax
				continue1:
				loop studentloop
			mov eax, [numDiv]
			cdq
			mov ebx, 2
			div ebx
			cmp edx, 0
			je continue2
			mov eax, [openCount]
			add eax, 1
			mov [openCount], eax
			continue2:
			mov ecx, [curLock]
			loop lockerloop
		mov eax, out2
		call print_string
		mov eax, [openCount]
		call print_int
		call print_nl
		call print_nl
		
      ; end main
      
      ; program exit
      popa
      mov eax, 0  ; return back to C
      leave                     
      ret
      ; end exit