section .text
	global _ft_list_remove_if
ft_list_remove_if:
	push rax
	push r8
	push r12
	push rdi
	mov rdi, 16
	call _malloc
	cmp rax, 0
	je bad
	mov r8, rax
	call _malloc
	cmp rax, 0
	je bad
	pop rdi
	mov rax [rdi]
loop1:
	cmp rax, 0
	je notdone
	cmp [rax + 8], 0
	je notdone
	push rdi
	mov rdi, [rax + 8]
	mov rdi, [rdi]
	push rax
	call rdx
	pop rdi
	cmp rax, 0
	je delete
het:
	pop rax
	mov rax, [rax + 8]
	jmp loop1
notdone:
	cmp rax, 0
	je done
	push rdi
	mov rdi, [rax]
	push rax
	call rdx
	cmp rax,0
	pop rax
	pop rdi
	jne done
	mov r12 ,[rax + 8]
	mov [rdi], r12
	push rdi
	mov rdi, [rax]
	call rcx
	mov rdi ,rax
	call _free
	pop rdi
done:
	pop rdi
	pop r12 
	pop r8 
	pop rax
	ret
delete:
	mov r8, [rax + 8]
	mov r12, [rax + 8]
	mov r12, [r12 + 8]
	mov [rax + 8], r12
	push rdi
	mov rdi, [r8]
	call rcx
	mov rdi , r8
	call _free
	pop rdi
	jmp het
	


	
	
