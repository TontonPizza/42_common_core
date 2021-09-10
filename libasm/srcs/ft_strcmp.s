section.text:
	global ft_strcmp

ft_strcmp:
	mov rcx, 0x0
	compare:
		mov byte dl, [rdi + rcx]
		cmp byte dl, [rsi + rcx]
			jg positive
			jb negative
		cmp byte dl, 0x0
			je zero
			inc rcx
			jmp compare
	positive:
		mov rax, 1
		ret
	negative:
		mov rax, -1
		ret
	zero:
		mov rax, 0
		ret