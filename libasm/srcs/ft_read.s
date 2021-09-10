section.text:
	global ft_read
	extern ___error

ft_read:
	mov rax, 0
	syscall
	mov rdi, rax
	cmp rax, 0x0
	jnge error_handler
	ret
error_handler:
	push rbp
	push rax
	imul rdi, -1
	call ___error
	pop rax
	pop rbp
	mov rax, -1
	ret