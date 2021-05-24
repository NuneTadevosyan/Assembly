section .text
	global _ft_read
_ft_write:
		cmp rsi, 0
		je done
		mov rax 0x2000003
		syscall
		jc done
done:
		mov rax, -1
		ret

