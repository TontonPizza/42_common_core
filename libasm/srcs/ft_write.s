section.text:
	global ft_write
	extern ___error
; rdi rsi rdx arg 1 2 3
ft_write:
	mov rax, 1
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