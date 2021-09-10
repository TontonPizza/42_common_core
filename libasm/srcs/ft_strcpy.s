section.text:
	global ft_strcpy
; rdi first arg rsi second arg
ft_strcpy:
	push rcx
	mov rcx, 0
	while1: cmp byte [rsi + rcx], 0x0
				je endwhile1
			mov al, byte [rsi + rcx]
			mov byte [rdi + rcx], al
			inc rcx
			jmp while1
	endwhile1:
			mov byte [rdi + rcx], 0x0
	mov rax, rdi
	pop rcx
	ret