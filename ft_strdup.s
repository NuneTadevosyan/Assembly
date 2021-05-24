section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strcpy
	extern _ft_strlen
_ft_strdup:
		cmp rdi, 0
		je done0
		push rsi
		call _ft_strlen
		push rdi
		mov rdi,rax
		inc rdi
		call _malloc
		cmp rax,0
		je done0
		mov rdi,rax
		pop rsi
		call _ft_strcpy
		pop rsi
		ret
done0:
	mov rax , 0
	ret

