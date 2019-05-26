org 0x7c00

_main:
	mov ax, cs
    mov ds, ax

	mov ah, 02h
	mov al, 4
	mov ch, 0
	mov cl, 2
	mov dh, 0
	mov bx, 0x9000
	int 13h

	cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp dword CODE_SEG:InProtectedMode

[bits 32]
InProtectedMode:
	mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
	mov ss, ax
	jmp 0x9000
	hlt

gdt_start:
	;GDT #0, It's empty
	dd 0x0
	dd 0x0

	;GDT #1, For code segment
	;Base = 0x0, length = 0xfffff
	gdt_code:
		dw 0xffff	
		dw 0x0		
		db 0x0		
		db 10011010b
		db 11001111b
		db 0x0		

	;GDT #2, For data segment
	;Base = 0x0, length = 0xfffff
	gdt_data:
		dw 0xffff
		dw 0x0
		db 0x0
		db 10010010b
		db 11001111b
		db 0x0

	gdt_descriptor:
		dw gdt_end - gdt_start - 1 ; size (16 bit), always one less of its true size
		dd gdt_start ; address (32 bit)

gdt_end:

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

times 510-($-$$) db 0
db 0x55,0xaa