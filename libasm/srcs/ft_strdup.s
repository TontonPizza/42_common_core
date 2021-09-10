section.text:
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc

ft_strdup:
	mov rax, 0
	call ft_strlen
	inc rax
	push rdi
	mov rdi, rax
	call malloc
	cmp rax, 0x0
		jz error
	pop rdi
	push rsi
	mov rsi, rdi
	mov rdi, rax
	call ft_strcpy
	pop rsi
	ret
error:
	mov rax, 0x0
	ret
