section .text
	global _ft_strlen

_ft_strlen:
xor rax, rax
loop: cmp 0, byte[rdi + rax]
	  je done
	  inc rax
	  jmp loop
done : ret

