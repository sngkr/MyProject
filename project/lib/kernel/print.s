TI_GDT equ 0
PRL0 equ 0
SELECTOR_VIDEO equ (0x003<<3) + TI_GDT + PRL0

[bits 32]

section .text

global put_char 

put_char:
	
	pushad 
	mov ax, SELECTOR_VIDEO
	mov gs, ax

;获取当前光标位置
;先获取高8位
	mov dx, 0x03d4
	mov al, 0x0e
	out dx, al
	mov  dx, 0x03d5
	in al, dx
	mov ah, al
	
;再获取低8位
	mov dx, 0x03d4
	mov al, 0x0f
	out dx,al
	mov dx, 0x03d5
	in al, dx

;将光标存入bx
	mov bx, ax
	mov ecx, [esp+36]

	cmp cl, 0xd
	jz .is_carriage_return
	cmp cl, 0xa
	jz .is_line_feed

	cmp cl, 0x8
	jz .is_backspace
	jmp .put_other


.is_backspace:


	dec bx
	shl bx,1
	
	mov byte [gs:bx], 0x20
	inc bx
	mov byte [gs:bx], 0x07
	shr bx, 1
	jmp .set_cursor

.put_other:
	shl bx,1	;光标左移一位相当于乘2
	
	mov [gs:bx], cl 
	inc bx
	mov byte [gs:bx], 0x07
	shr bx,1
	inc bx
	cmp bx, 2000
	jl .set_cursor


.is_line_feed:

.is_carriage_return:
	xor dx, dx
	mov ax, bx
	mov  si ,80
	
	div si
	sub bx, dx
	

.is_carriage_return_end:
	add bx, 80
	cmp bx, 2000

                                                                                                                                                                                                                                                                                                                                                     
.is_line_feed_end:
	jl .set_cursor


.roll_screen:
	cld
	mov ecx ,960
	
	mov esi, 0xc00b80a0
	mov edi, 0xc00b8000
	rep movsd
	
	mov ebx, 3840
	mov ecx, 80
	
.cls:
	mov word [gs:ebx] , 0x0720	
	add ebx,2
	loop	.cls
	mov bx, 1920
	
.set_cursor:
	
	mov dx, 0x03d4
	mov al, 0x0e
	out dx, al
	mov dx, 0x03d5
	mov al, bh
	out dx,al

	mov dx, 0x03d4
	mov al, 0x0f
	out dx, al
	mov dx,	0x03d5
	mov al, bl
	out dx,al
.put_char_done:
	popad
	ret
