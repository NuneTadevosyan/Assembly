section .text
	global _ft_strcmp

_ft_strcmp:
		push rcx
		push rdx
		xor rcx, rcx
		cmp byte[rdi + rcx], 0
		je equal
loop:
		cmp byte[rdi + rcx], 0
		je equal
		mov dh, byte[rdi + rcx]
		cmp dh, byte[rsi + rcx]
		inc rcx
		je loop
		jl less
		jmp great
equal:
	cmp byte[rsi + rcx], 0
	je edone
less:
	mov rax, -1
	pop rdx
	pop rcx
	ret
edone: 
	mov rax 0
	pop rdx
	pop rcx
	ret
great:
	mov rax 1
	pop rdx
	pop rcx
	ret

	
