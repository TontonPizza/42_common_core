section.text:
	global ft_strlen

ft_strlen:
	push rcx
	mov rcx, 0
	while1:		cmp byte [rdi + rcx], 0x0
					je endwhile1
				inc rcx
				jmp while1
	endwhile1:
	mov rax, rcx
	pop rcx
	ret
