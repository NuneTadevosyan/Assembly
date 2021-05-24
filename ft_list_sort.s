section .text
	extern _free
	extern _malloc
	global _ft_list_sort
ft_list_sort:
	push rax
	push rcx
	push rdx
	push rsi
	push rdi
	mov rdi, 16
	call _malloc
	cmp rax, 0
	je bad
	mov rdx,rax
	call _malloc
	cmp rax, 0
	je bad
	pop rdi
	mov rax, [rdi]
	mov rcx, rsi
loop1:
	cmp rax,0
	je done
	mov rdx, [rdi]
loop2:
	cmp [rdx + 8], 0
	je loop1
	mov rdi, [rdx]
	mov rsi, [rdx + 8]
	mov rsi, [rsi]
	push rax
	call rcx
	cmp rax, 0
	jg swap
sh:
	pop rax
	mov rdx, [rdx + 8]
	jmp loop1
done:
	pop rsi
	pop rdx
	pop rcx
	pop rax
	ret
swap:
	push r8
	push r12
	mov r8, [rdx]
	mov r12, [rdx + 8]
	mov r12, [r12]
	mov [rdx], r12
	mov r12, r8
	pop r12
	pop r8
	jmp sh


