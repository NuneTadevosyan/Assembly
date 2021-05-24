section .text
	global _ft_list_push_front
	extern _malloc
ft_list_push_front:
	push rdx
	push rdi
	push rsi
	mov rdi,16 ; 8byte data in 8 el next i cucich
	call _malloc
	pop rsi
	pop rdi
	cmp rax, 0
	je  bad
	mov [rax], rsi ; datan em qcum
	mov rdx, [rdi]
	mov [rax + 8], rdx
	mov [rdi], rax
bad:
	ret
