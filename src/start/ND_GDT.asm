/* This file starts the GDT */
.global gdt_flush
gdt_flush:
	lgdtl gp
	movl $0x10, %eax
	movl %eax, %ds
	movl %eax, %es
	movl %eax, %fs
	movl %eax, %gs
	movl %eax, %ss
	jmp flush2
flush2:
	ret
	
