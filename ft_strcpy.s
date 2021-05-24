section .text
	global _ft_strcpy
_ft_strcpy:
	push rcx
	push rdx
	xor rcx,rcx
loop:
	mov dh, byte[rsi + rcx]
	mov byte[rdi + rcx],dh
	cmp 0, byte[rsi + rcx]
	je done
	inc rcx
	jmp loop
done:
	mov rax rdi
	pop rdx
	pop rcx
	ret
