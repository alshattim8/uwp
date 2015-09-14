; CS3230 CAOS
; file: thirdhw.asm
; John W Hunter

; To create executable and run:
; nasm -f elf thirdhw.asm
; gcc -m32 thirdhw.o driver.c asm_io.o
; ./a.exe or ./a.out

%include "asm_io.inc"

;----------------------------------------
; Program Main
segment .data
   menuMsg  db "PLEASE SELECT AN OPTION FROM THE MENU:", 0xA
            db "--------------------------------------", 0xA  
            db "1. Enter a new string", 0xA
            db "2. Count the number of words in your string", 0xA
            db "3. Remove leading and duplicate blank characters in your recieved string", 0xA
            db "4. Reverse the words in your string", 0xA
            db "5. Test if your string is palindrome", 0xA
            db "6. Exit", 0xA
				db "", 0xA
				db "Choice #: ", 0
   errorMsg db "Not a valid command!", 0
   exitMsg db "Good Bye", 0
   readStringMsg db "Your string is: ", 0
   countWordsMsg1 db "The number of words in '", 0
   countWordsMsg2 db "' is ", 0
   stringLengthMsg db "String length is: ", 0
   removeSpacesMsg db "After removing leading and duplicate blank characters: ", 0
   isPalinMsg db "The string '", 0
   isPalinMsgTrue db "' is palindrome", 0
   isPalinMsgFalse db "' is not palindrome", 0
   max_string_size equ 100
segment .bss
   myString resb max_string_size
   wordCount resd 1
   stringLength resd 1
   formattedString resb max_string_size
   isPalindrome resd 1
segment .text
   global _asm_main
   _asm_main:
      ; setup routine
      enter 0, 0
      pusha
      ; end setup
      
      ; program main
      
      menu:
         call print_nl
         mov eax, menuMsg
         call print_string
         
         call read_int
         call print_nl
         
         cmp eax, 1
         je select_read_string
         cmp eax, 2
         je select_count_words
         cmp eax, 3
         je select_remove_spaces
         cmp eax, 4
         je select_reverse_words
         cmp eax, 5
         je select_is_palindrome
         cmp eax, 6
         je exit
;         cmp eax, 7
;         je select_string_length
         
         mov eax, errorMsg
         call print_string
         call print_nl
         jmp menu
         
      select_read_string:
         mov eax, myString
         push eax
         call read_string
         add esp, 4
         mov eax, myString
         push eax
         call read_string
         add esp, 4
         mov eax, readStringMsg
         call print_string
         mov eax, myString
         call print_string
         call print_nl
         jmp menu
         
      select_count_words:
         mov eax, myString
         push eax
         mov eax, wordCount
         push eax
         call count_words
         add esp, 8
         mov eax, countWordsMsg1
         call print_string
         mov eax, myString
         call print_string
         mov eax, countWordsMsg2
         call print_string
         mov eax, [wordCount]
         call print_int
         call print_nl
         jmp menu
      
      select_remove_spaces:
         mov eax, stringLength
         push eax
         mov eax, myString
         push eax
         call find_length
         add esp, 8
         
         mov eax, formattedString
         push eax
         mov eax, stringLength
         push eax
         mov eax, myString
         push eax
         call remove_spaces
         add esp, 12
         
         mov eax, readStringMsg
         call print_string
         mov eax, myString
         call print_string
         call print_nl
         mov eax, removeSpacesMsg
         call print_string
         mov eax, formattedString
         call print_string
         call print_nl
         jmp menu
         
      select_reverse_words:
         mov eax, readStringMsg
         call print_string
         mov eax, myString
         call print_string
         call print_nl
         
         mov eax, stringLength
         push eax
         mov eax, myString
         push eax
         call find_length
         add esp, 8
         
         mov eax, formattedString
         push eax
         mov eax, stringLength
         push eax
         mov eax, myString
         push eax
         call remove_spaces
         add esp, 12
      
         mov eax, stringLength
         push eax
         mov eax, formattedString
         push eax
         call find_length
         add esp, 8
         
         mov eax, stringLength
         push eax
         mov eax, formattedString
         push eax
         call reverse_words
         add esp, 8
         
         jmp menu
      
      select_is_palindrome:
         mov eax, stringLength
         push eax
         mov eax, myString
         push eax
         call find_length
         add esp, 8
         
         mov eax, isPalindrome
         push eax
         mov eax, stringLength
         push eax
         mov eax, myString
         push eax
         call is_palindrome
         add esp, 12
         
         cmp [isPalindrome], dword 0
         je not_palin_msg
         mov eax, isPalinMsg
         call print_string
         mov eax, myString
         call print_string
         mov eax, isPalinMsgTrue
         call print_string
         call print_nl         
         jmp menu
         not_palin_msg:
         mov eax, isPalinMsg
         call print_string
         mov eax, myString
         call print_string
         mov eax, isPalinMsgFalse
         call print_string
         call print_nl         
         jmp menu
      
;      select_string_length:
         mov eax, stringLength
         push eax
         mov eax, myString
         push eax
         call find_length
         add esp, 8
         mov eax, stringLengthMsg
         call print_string
         mov eax, [stringLength]
         call print_int
         call print_nl
         jmp menu
      
      exit:
         mov eax, exitMsg
         call print_string
         call print_nl
         call print_nl
      
      ; end main
      
      ; program exit
      popa
      mov eax, 0
      leave
      ret
      ; end exit
      
;----------------------------------------
; A subprogram to read a string
; WARNING: Due to unknown errors this subprogram needs to be called twice
segment .data
   promptReadString db "Enter a new string: ", 0
segment .text
   read_string:
      push ebp
      mov ebp, esp
      
      ; eax+8 - string
      
      mov ebx,[ebp+8]
      mov esi,0
      mov eax, promptReadString
      call print_string
      call print_nl
      mov ecx, max_string_size

      get_string:
         call read_char
         cmp  al, 0xA
         je exit_get_string
         mov [ebx+esi], al
         add esi,1
         loop get_string
      exit_get_string:
      mov byte[ebx+esi], 0
      
      pop ebp
      ret

;----------------------------------------
; A subprogram count the number of words in a string
segment .bss
   inWord resd 1
   tempCount resd 1
segment .text
   count_words:
      push ebp
      mov ebp, esp
      
      ; ebp+8 - word count
      ; ebp+12 - string
      
      mov eax, 0
      mov [inWord], eax
      mov [tempCount], eax
      mov esi, 0
      mov ecx, max_string_size
      mov ebx, [ebp+12]
      count_loop:
         mov al, byte[ebx+esi]
         cmp al, 0xA
         je exit_count_loop
         cmp al, 0x20
         je not_in_word
         mov eax, [inWord]
         cmp eax, 1
         je cont_count_loop
         mov eax, 1
         mov [inWord], eax
         mov eax, [tempCount]
         add eax, 1
         mov [tempCount], eax
         jmp cont_count_loop
         not_in_word:
            mov eax, 0
            mov [inWord], eax
         cont_count_loop:
         add esi, 1
         loop count_loop
      exit_count_loop:
      mov ebx, [ebp+8] 
      mov eax, [tempCount]
      mov [ebx], eax
      
      pop ebp
      ret
      
;----------------------------------------
; A subprogram to reverse the order of the words in a string and print it
segment .data
   reverseMsg db "After reversing the words:", 0
segment .bss
   reverseString resb max_string_size
   reverseWordSize resd 1
   temp_ecx resd 1
segment .text
   reverse_words:
      push ebp
      mov ebp, esp
      
      ; ebp+8 - string
      ; ebp+12 - string length
      
      mov eax, [ebp+12]
      mov ecx, [eax]
      mov esi, 0
      mov edi, ecx
      sub edi, 1
      mov ebx, [ebp+8]
      reverse_loop:
         mov al, [ebx+esi]
         mov [reverseString+edi], al
         add esi, 1
         sub edi, 1
         loop reverse_loop
      mov [reverseString+esi], byte 0
      
      mov eax, reverseMsg
      call print_string
      
      mov eax, 0
      mov [reverseWordSize], eax
      mov eax, [ebp+12]
      mov ecx, [eax]
      mov esi, 0
      reverse_print_loop:
         mov al, [reverseString+esi]
         cmp al, 0x20
         je goto_inner_loop
         ;mov eax, [ebp+12]
         ;cmp esi, eax
         mov ebx, esi
         add ebx, 1
         mov al, [reverseString+ebx]
         cmp al, byte 0
         je goto_inner_loop
         jmp goto_else
         
         goto_inner_loop:
         mov [temp_ecx], ecx
         
         mov ecx, [reverseWordSize]
         add ecx, 1
         mov edi, 0
         inner_loop:
            mov ebx, esi
            sub ebx, edi
            mov al, [reverseString+ebx]
            call print_char
            add edi, 1
            loop inner_loop
         mov al, 0x20
         call print_char
         mov eax, 0
         mov [reverseWordSize], eax
         
         mov ecx, [temp_ecx]
         jmp cont_reverse_print_loop
         
         goto_else:
            mov eax, [reverseWordSize]
            add eax, 1
            mov [reverseWordSize], eax
         cont_reverse_print_loop:
         add esi, 1
         loop reverse_print_loop
      call print_nl
      
      pop ebp
      ret
      
;----------------------------------------
; A subprogram to remove leading, trailing, and duplicate blank spaces in a string
segment .bss
   isFront resd 1
   tempChar resb 1
segment .text
   remove_spaces:
      push ebp
      mov ebp, esp
      
      ; ebp+8 - string
      ; ebp+12 - string length
      ; ebp+16 - formatted string
      
      mov eax, 0
      mov [isFront], eax
      mov al, 0x61
      mov [tempChar], al
      mov ebx, [ebp+8]
      mov edx, [ebp+16]
      
      mov esi, 0 ; i
      mov edi, 0 ; j
      mov eax, [ebp+12]
      mov ecx, [eax]
      
      remove_loop:
         cmp [ebx+esi], byte 0x20
         je not_space
            mov eax, 0
            mov [isFront], eax
            mov al, [tempChar]
            cmp al, 0x20
            jne not_space_2
               mov [edx+edi], byte 0x20
               add edi, 1
            not_space_2:
            mov al, [ebx+esi]
            mov [edx+edi], al
            add edi, 1
         not_space:
         mov eax, [isFront]
         cmp eax, 0
         jne cont_remove_loop
            mov al, [ebx+esi]
            mov [tempChar], al
         cont_remove_loop:
         add esi, 1
         loop remove_loop
      mov [edx+edi], byte 0
      
      pop ebp
      ret
      
;----------------------------------------
; A subprogram to determine if a string is palindrome or not
segment .bss
   returnPalin resd 1
segment .text
   is_palindrome:
      push ebp
      mov ebp, esp
      
      ; ebp+8 - string
      ; ebp+12 - string length
      ; ebp+16 - is palindrome
      
      mov eax, [ebp+12]
      mov ecx, [eax]
      mov edi, [eax] ; j
      sub edi, 1
      mov esi, 0 ; i
      mov edx, [ebp+8]
      palin_loop:
         mov eax, [edx+esi]
         mov ebx, [edx+edi]
         cmp al, bl
         je cont_palin
            mov eax, 0
            mov [returnPalin], eax
            jmp end_palin_loop
         cont_palin:
         sub edi, 1
         add esi, 1
         loop palin_loop
      mov eax, 1
      mov [returnPalin], eax
      end_palin_loop:
      mov eax, [ebp+16]
      mov ebx, [returnPalin]
      mov [eax], ebx
      
      pop ebp
      ret

;----------------------------------------
; A subprogram to return the length of a given string
segment .text
find_length:
	push ebp
	mov ebp,esp
	
   ; ebp+8 - string
   ; ebp+12 - length
   
	mov eax,0
	mov ebx,[ebp+8]
	mov esi,0
	mov ecx,max_string_size
   length_loop:
      cmp [ebx+esi],dword 0
      je length_exit
      inc eax
      add esi,1
      loop length_loop
   length_exit:
   mov eax, [ebp+12]
   mov [eax], esi
   
	pop ebp
	ret

