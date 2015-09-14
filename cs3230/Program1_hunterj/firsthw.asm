; CS3230 CAOS
; file: firsthw.asm
; John W Hunter

; To create executable :
; nasm -f elf firsthw.asm
; gcc -m32 firsthw.o driver.c asm_io.o
; ./a.exe or ./a.out

%include "asm_io.inc"

; initialized data is put in the .data segment
segment .data
   out1 db "Enter first integer: ", 0
   out2 db "Enter second integer: ", 0
   out3 db "The sum is: ", 0
   out4 db "The difference is: ", 0
   out5 db "The product is: ", 0
   out6 db "The quotient is: ", 0

; uninitialized data is put in the .bss segment
segment .bss
   integer1 resd 1
   integer2 resd 1

; code is put in the .text segment
segment .text
   global  _asm_main
   _asm_main:
      ; setup routine
      enter 0, 0 
      pusha
      ; end setup
      
      ; main program functionality
      
      ; print out1
      call print_nl
      mov eax, out1
      call print_string
      
      ; read integer1
      call read_int
      mov [integer1], eax
      
      ; print out2
      mov eax, out2
      call print_string
      
      ; read integer2
      call read_int
      mov [integer2], eax
      
      ; addition
      mov eax, out3
      call print_string
      mov eax, [integer1]
      add eax, [integer2]
      call print_int 
      
      ; subtraction
      call print_nl
      mov eax, out4
      call print_string
      mov eax, [integer1]
      sub eax, [integer2]
      call print_int
      
      ; multiplication
      call print_nl
      mov eax, out5
      call print_string
      mov eax, [integer1]
      imul eax, [integer2]
      call print_int
      
      ; division
      call print_nl
      mov eax, out6
      call print_string
      mov eax, [integer1]
		cdq
      mov ebx, [integer2]
      idiv ebx
      call print_int
      
      call print_nl
      call print_nl
      
      ; end main

      ;dump_regs 1 ; dump out register values
      ;dump_mem 2, integer1, 0 ; dump out memory
      ;dump_mem 3, integer2, 0

      ; program exit
      popa
      mov eax, 0  ; return back to C
      leave                     
      ret
      ; end exit