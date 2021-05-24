section .text
	global _ft_list_size

ft_list_size:
	mov rsi, rdi
	xor rax, rax
loop:
	cmp rdi, 0
	je done
	mov rdi [rdi + 8]
	inc rax
	jmp loop
done:
	mov rdi rsi
	ret
