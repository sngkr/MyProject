setup_page:
	mov ecx, 4096
	mov esi,0 
	.clear_page_dir:
	mov byte [PAGE_DIR_TABLE_POS + esi],0
	inc esi
	loop .clear_page_dir
	
	or eax PG_US_U | PG_RW_W | PG_P
	mov [PAGE_DIR_TABLE_POS + 0x0], eax
	mov [PAGE_DIR_TABLE_POS + 0xc00], eax
	
	sub eax, 0x1000
	mov [PAGE_DIR_TABLE_POS + 4092], eax
	
	

	mov ecx, 256
	mov esi,0
	mov edx, PG_US_U | PG_RW_W | PG_P
	.create_pte:
	mov [ebx+esi*4],edx
	

	add edx, 4096
	inc esi
	loop .create_pte
	
	mov eax, PAGE_DIR_TABLE_POS
	add eax, 0x2000
	or eax, PG_US_U| PG_RW_W | PG_P
	mov ebx, PAGE_DIR_TABLE_POS
	mov ecx, 254
	mov sei,769
	.create_kernel_pde:
	mov [ebx + esi*4 ] , eax
	inc sei

	add eax, 0x1000
	loop .create_kernel_pde


	ret

