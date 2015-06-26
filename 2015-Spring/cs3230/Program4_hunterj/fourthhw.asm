; CS3230 CAOS
; file: fourthhw.asm
; John W Hunter

; To create executable and run:
; nasm -f elf fourthhw.asm
; gcc -m32 fourthhw.o driver.c asm_io.o
; ./a.exe or ./a.out

%include "asm_io.inc"

struc Movie 
   .Title: resb movie_title_size 
   .Price: resd 1
   .size:
   endstruc

;----------------------------------------
; Program Main
segment .data
   menuMsg  db "PLEASE SELECT AN OPTION FROM THE MENU:", 0xA
            db "--------------------------------------", 0xA  
            db "1. Check to see if the queue is empty", 0xA
            db "2. Check to see if the queue is full", 0xA
            db "3. Enqueue an item", 0xA
            db "4. Dequeue an item", 0xA
            db "5. Clear the queue", 0xA
            db "6. Display the queue", 0xA
            db "7. Export the queue to 'out.txt'", 0xA
            db "8. Exit", 0xA
            db "", 0xA
            db "Choice #: ", 0
   errorMsg db "Not a valid command!", 0
   exitMsg db "Good Bye", 0
   qIsEmptyMsg db "The queue is empty", 0
   qNotEmptyMsg db "The queue is not empty", 0
   qIsFullMsg db "The queue is full", 0
   qNotFullMsg db "The queue is not full", 0
   max_queue_size equ 4
   movie_title_size equ 11
segment .bss
   qSize resd 1
   qEmpty resd 1
   qFull resd 1
   front resd 1
   rear resd 1
   myQueue resb Movie.size*max_queue_size
segment .text
   global _asm_main
   _asm_main:
      ; setup routine
      enter 0, 0
      pusha
      ; end setup
      
      ; initialize
      mov eax, 0
      mov [qSize], eax
      mov eax, myQueue
      mov [front], eax
      mov [rear], eax      
      
      ; program main
      
      menu:
         ;dump_mem 1, myQueue, Movie.size*max_queue_size
         call print_nl
         mov eax, menuMsg
         call print_string
         
         call read_int
         call print_nl
         
         cmp eax, 1
         je select_is_empty
         cmp eax, 2
         je select_is_full
         cmp eax, 3
         je select_enqueue
         cmp eax, 4
         je select_dequeue
         cmp eax, 5
         je select_clear
         cmp eax, 6
         je select_display
         cmp eax, 7
         je select_export_queue
         cmp eax, 8
         je exit
         
         mov eax, errorMsg
         call print_string
         call print_nl
         jmp menu
      
      select_is_empty:
         mov eax, qSize
         push eax
         mov eax, qEmpty
         push eax
         call is_empty
         add esp, 8
         
         mov eax, [qEmpty]
         mov ebx, 1
         cmp eax, ebx
         je print_is_empty
         jne print_not_empty
         
         print_is_empty:
            mov eax, qIsEmptyMsg
            call print_string
            call print_nl
            jmp menu
            
         print_not_empty:
            mov eax, qNotEmptyMsg
            call print_string
            call print_nl
            jmp menu
            
      select_is_full:
         mov eax, qSize
         push eax
         mov eax, qFull
         push eax
         call is_full
         add esp, 8
         
         mov eax, [qFull]
         mov ebx, 1
         cmp eax, ebx
         je print_is_full
         jne print_not_full
         
         print_is_full:
            mov eax, qIsFullMsg
            call print_string
            call print_nl
            jmp menu
            
         print_not_full:
            mov eax, qNotFullMsg
            call print_string
            call print_nl
            jmp menu
            
      select_enqueue:
         mov eax, myQueue
         push eax
         mov eax, qSize
         push eax
         mov eax, rear
         push eax
         call enqueue
         add esp, 12
         jmp menu
         
      select_dequeue:
         mov eax, myQueue
         push eax
         mov eax, qSize
         push eax
         mov eax, front
         push eax
         call dequeue
         add esp, 12
         jmp menu
         
      select_clear:
         mov eax, qSize
         push eax
         mov eax, rear
         push eax
         mov eax, front
         push eax
         mov eax, myQueue
         push eax
         call clear
         add esp, 16
         jmp menu
         
      select_display:
         mov eax, front
         push eax
         mov eax, rear
         push eax
         mov eax, myQueue
         push eax
         call display
         add esp, 12
         jmp menu
      
      select_export_queue:
         mov eax, front
         push eax
         mov eax, rear
         push eax
         mov eax, myQueue
         push eax
         call export_queue
         add esp, 12
         jmp menu
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
; A subprogram to check if the queue is empty
segment .text
   is_empty:
      push ebp
      mov ebp, esp
      
      ; ebp+8 - qEmpty
      ; ebp+12 - qSize
      
      mov eax, [ebp+12]
      mov ebx, 0
      cmp [eax], ebx
      je is_empty_true
      jne is_empty_false
      
      is_empty_true:
         mov eax, 1
         mov ebx, [ebp+8]
         mov [ebx], eax
         jmp exit_is_empty
      
      is_empty_false:
         mov eax, 0
         mov ebx, [ebp+8]
         mov [ebx], eax
         jmp exit_is_empty
      
      exit_is_empty:
      
      pop ebp
      ret

;----------------------------------------
; A subprogram to check if the queue is full
segment .text
   is_full:
      push ebp
      mov ebp, esp
      
      ; ebp+8 - qFull
      ; ebp+12 - qSize
      
      mov eax, max_queue_size
      mov ebx, [ebp+12]
      cmp [ebx], eax
      jge is_full_true
      jl is_full_false
      
      is_full_true:
         mov eax, 1
         mov ebx, [ebp+8]
         mov [ebx], eax
         jmp exit_is_full
      
      is_full_false:
         mov eax, 0
         mov ebx, [ebp+8]
         mov [ebx], eax
         jmp exit_is_full
      
      exit_is_full:
      
      pop ebp
      ret

;----------------------------------------
; A subprogram to enqueue a movie item
segment .data
   enqueueComplete db "Item added to queue", 0
   enqueueError db "Cannot enqueue, queue is full", 0
   promptPrice db "Enter movie price (integer value): ", 0
segment .bss
   rearPtr resd 1
   checkFull resd 1
segment .text
   enqueue:
      push ebp
      mov ebp, esp
      
      ; ebp+8 - rear
      ; ebp+12 - size
      ; ebp+16 - myQueue
      
      ;check to see if queue is full
      mov eax, [ebp+12]
      push eax
      mov eax, checkFull
      push eax
      call is_full
      add esp, 8
         
      mov eax, [checkFull]
      mov ebx, 1
      cmp eax, ebx
      je cannot_enqueue
      jne cont_enqueue
         
      cannot_enqueue:
         mov eax, enqueueError
         call print_string
         call print_nl
         jmp exit_enqueue
            
      cont_enqueue:
      
      ; set pointer to rear
      mov eax, [ebp+8]
      mov ebx, [eax]
      mov [rearPtr], ebx
      
      ; read in movie title
      mov eax, [rearPtr]
      add eax, Movie.Title
      push eax
      call read_title
      add esp, 4
      mov eax, [rearPtr]
      add eax, Movie.Title
      push eax
      call read_title
      add esp, 4
      
      ; read in movie price
      mov eax, promptPrice
      call print_string
      
      mov esi, [rearPtr]
      call read_int
      mov [esi + Movie.Price], eax
      
      call print_nl
      
      ; mov rear
      mov esi, [ebp+8]
      mov eax, [esi]
      add eax, Movie.size
      mov edi, [ebp+16]
      mov ebx, edi
      add ebx, Movie.size
      add ebx, Movie.size
      add ebx, Movie.size
      cmp eax, ebx
      jle cont_mov_rear
      mov eax, edi
      cont_mov_rear:
      mov [esi], eax
      
      ; increment size
      mov edx, [ebp+12]
      mov eax, [edx]
      add eax, 1
      mov edx, [ebp+12]
      mov [edx], eax
      
      ; print out confirmation of enqueue
      mov eax, enqueueComplete
      call print_string
      call print_nl
      
      exit_enqueue:
      
      pop ebp
      ret
      
;----------------------------------------
; A subprogram to remove an item from the queue
segment .data
   dequeueMsg db "Item removed from queue:", 0
   dequeueError db "Cannot dequeue, queue is empty", 0
   deMsg1 db "Title: ", 0
   deMsg2 db ", Price: ", 0
segment .bss
   frontPtr resd 1
   checkEmpty resd 1
segment .text
   dequeue:
      push ebp
      mov ebp, esp
      
      ; ebp+8 - front
      ; ebp+12 - size
      ; ebp+16 - myQueue
      
      ;check to see if queue is empty
      mov eax, [ebp+12]
      push eax
      mov eax, checkEmpty
      push eax
      call is_empty
      add esp, 8
         
      mov eax, [checkEmpty]
      mov ebx, 1
      cmp eax, ebx
      je cannot_dequeue
      jne cont_dequeue
         
      cannot_dequeue:
         mov eax, dequeueError
         call print_string
         call print_nl
         jmp exit_dequeue
            
      cont_dequeue:
      
      ; set pointer to front
      mov eax, [ebp+8]
      mov ebx, [eax]
      mov [frontPtr], ebx
      
      ; print out removed item
      mov esi, [frontPtr]
      mov eax, dequeueMsg
      call print_string
      call print_nl
      mov eax, deMsg1
      call print_string
      mov eax, esi
      add eax, Movie.Title
      call print_string
      mov eax, deMsg2
      call print_string
      mov eax, [esi+Movie.Price]
      call print_int
      call print_nl
      
      ; clear out values at front location
      mov eax, [frontPtr]
      mov esi, 0
      add eax, Movie.Title
      mov ecx, movie_title_size
      dequeue_clear_string:
         mov byte[eax+esi], 0
         add esi, 1
         loop dequeue_clear_string
      mov eax, [frontPtr]
      add eax, Movie.Price
      mov dword[eax], 0
      
      ; move front location
      mov esi, [ebp+8]
      mov eax, [esi]
      add eax, Movie.size
      mov edi, [ebp+16]
      mov ebx, edi
      add ebx, Movie.size
      add ebx, Movie.size
      add ebx, Movie.size
      cmp eax, ebx
      jle cont_mov_front
      mov eax, edi
      cont_mov_front:
      mov [esi], eax
      
      ; decremet size
      mov edx, [ebp+12]
      mov eax, [edx]
      sub eax, 1
      mov edx, [ebp+12]
      mov [edx], eax
      
      exit_dequeue:
      
      pop ebp
      ret


;----------------------------------------
; A subprogram to clear out the queue
segment .data
   clearingMsg db "Removing all items from queue...", 0
   clearMsg db "The queue is cleared", 0
segment .text
   clear:
      push ebp
      mov ebp, esp
      
      ; ebp+8 - myQueue
      ; ebp+12 - front
      ; ebp+16 - rear
      ; ebp+20 - size
      
      mov eax, clearingMsg
      call print_string
      call print_nl
      
      mov ebx, [ebp+20]
      mov eax, [ebx]
      cmp eax, 0
      je cont_clear
      mov ecx, eax
      remove_all_loop:
         mov ebx, [ebp+20]
         mov eax, [ebx]
         cmp eax, 0
         je cont_clear
         mov eax, [ebp+8]
         push eax
         mov eax, [ebp+20]
         push eax
         mov eax, [ebp+12]
         push eax
         call dequeue
         add esp, 12
         loop remove_all_loop
      cont_clear:
      
      ; print out msg
      mov eax, clearMsg
      call print_string
      call print_nl
      
      pop ebp
      ret

;----------------------------------------
; A subprogram to display the queue
segment .data
   dMsg1 db "Items in queue:", 0
   dMsg2 db "Title: ", 0
   dMsg3 db ", Price: ", 0
segment .bss
   startPtr resd 1
   endPtr resd 1
segment .text
   display:
      push ebp
      mov ebp, esp
      
      ; ebp+8 - queue
      ; ebp+12 - rear
      ; ebp+16 - front
      
      mov eax, dMsg1
      call print_string
      call print_nl
      
      mov esi, [ebp+16]
      mov eax, [esi]
      mov [startPtr], eax
      
      mov esi, [ebp+12]
      mov eax, [esi]
      mov [endPtr], eax
      
      mov ecx, max_queue_size
      display_loop:
         mov esi, [startPtr]
         mov edi, [endPtr]
         cmp esi, edi
         je exit_display_loop
      
         mov eax, dMsg2
         call print_string
         mov esi, [startPtr]
         add esi, Movie.Title
         mov eax, esi
         call print_string
         mov eax, dMsg3
         call print_string
         mov eax, [esi+Movie.Price]
         call print_int
         call print_nl
         
         ; move start location
         mov eax, [startPtr]
         add eax, Movie.size
         mov edi, [ebp+8]
         mov ebx, edi
         add ebx, Movie.size
         add ebx, Movie.size
         add ebx, Movie.size
         cmp eax, ebx
         jle cont_display_loop
         mov eax, edi
         cont_display_loop:
         mov [startPtr], eax
         
         loop display_loop
         
      exit_display_loop:      
      
      pop ebp
      ret

;----------------------------------------
; A subprogram to export the queue to a text file
; WARNING: FOR UNKOWN REASONS, THIS FUNCTION DECIDED TO FAIL TO WRITE
segment .data
   filename db "./out.txt", 0
   newLine db 0xA
   export1 db "Writing to file...", 0
   export2 db "Write finished!", 0
segment .bss
   startPtr2 resd 1
   endPtr2 resd 1
   fileDesc resd 1
   stringLength resd 1
segment .text
   export_queue:
      push ebp
      mov ebp, esp
      
      ; ebp+8 - queue
      ; ebp+12 - rear
      ; ebp+16 - front
      
      mov eax, export1
      call print_string
      call print_nl
      
      ; open file
      mov ebx, filename     ; EBX=path of the file to open
      mov ecx, 2            ; Access Bits: read and write mode
      mov eax, 5            ; System call : open
      int 0x80              ; Calling system Interrupt
      mov [fileDesc], eax
   
      ; writing info loop
      mov esi, [ebp+16]
      mov eax, [esi]
      mov [startPtr2], eax
      
      mov esi, [ebp+12]
      mov eax, [esi]
      mov [endPtr2], eax
      
      mov ecx, 4
      export_loop:
         mov esi, [startPtr2]
         mov edi, [endPtr2]
         cmp esi, edi
         je exit_export_loop
         
         ; exporting info
         mov esi, [startPtr2]
         add esi, Movie.Title
         
         mov eax, stringLength
         push eax
         mov eax, esi
         push eax
         call find_length
         add esp, 8
         
         mov ebx, [fileDesc]         ; EBX= The file descriptor  
         mov ecx, esi        ; ECX= address of the string that we want to write 
         mov edx, movie_title_size     ; EDX= size of the string(#bytes)that we want to write
         mov eax, 4           ; System call : write  . Note: System call Read is 3
         int 0x80             ; Calling system Interrupt
         
         ; WARNING: UNSURE OF HOW TO ACTUALLY OUTPUT A INTEGER!
         ; mov esi, [startPtr2]
         ; add esi, Movie.Price
         
         ; mov ebx, [fileDesc]         ; EBX= The file descriptor  
         ; mov ecx, esi        ; ECX= address of the string that we want to write 
         ; mov edx, 4     ; EDX= size of the string(#bytes)that we want to write
         ; mov eax, 4           ; System call : write  . Note: System call Read is 3
         ; int 0x80             ; Calling system Interrupt
         
         mov ebx, [fileDesc]         ; EBX= The file descriptor  
         mov ecx, newLine        ; ECX= address of the string that we want to write 
         mov edx, 1     ; EDX= size of the string(#bytes)that we want to write
         mov eax, 4           ; System call : write  . Note: System call Read is 3
         int 0x80             ; Calling system Interrupt
         
         ; move start location
         mov eax, [startPtr2]
         add eax, Movie.size
         mov edi, [ebp+8]
         mov ebx, edi
         add ebx, Movie.size
         add ebx, Movie.size
         add ebx, Movie.size
         cmp eax, ebx
         jle cont_export_loop
         mov eax, edi
         cont_export_loop:
         mov [startPtr2], eax
         
         sub ecx, 1
         jnz export_loop
         
      exit_export_loop: 
      
      ; close file
      mov ebx, filename   ; EBX=path of the file to open
      mov eax, 6          ; System call : close
      int 0x80            ; Calling system Interrupt
      
      mov eax, export2
      call print_string
      call print_nl
      
      pop ebp
      ret

;----------------------------------------
; A subprogram to read a string
; WARNING: Due to unknown errors this subprogram needs to be called twice
segment .data
   promptReadTitle db "Enter movie title (MAX 10 CHARS): ", 0
segment .text
   read_title:
      push ebp
      mov ebp, esp
      
      ; eax+8 - title
      
      mov ebx,[ebp+8]
      mov esi,0
      mov eax, promptReadTitle
      call print_string
      mov ecx, movie_title_size

      get_string:
         call read_char
         cmp  al, 0xA
         je exit_get_string
         mov [ebx+esi], al
         add esi,1
         loop get_string
      exit_get_string:
      mov byte[ebx+esi], 0
      call print_nl
      
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
	mov ecx, movie_title_size
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
