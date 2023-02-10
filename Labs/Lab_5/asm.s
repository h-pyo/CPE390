
	.globl _Z3f1ay
_Z3f1ay:	
	# write a function that counts from 0 to n-1 (which is in %rdi)
    xor %rcx, %rcx
    sub $1, %rdi # makes rdi n-1
L1: inc %rcx 
    cmp %rcx, %rdi
    jne L1
    mov %rcx, %rax
	  ret

	.globl _Z3f1by
_Z3f1by:
	# write a function that counts from n down to 1
    xor %rax, %rax
    mov %rdi, %rax
L2: sub $1, %rax
    cmp $1, %rax
    jne L2
	  ret

	.globl _Z3f1cy
_Z3f1cy:
	# Write a function that counts from n down to 1 without using the compare (sub will do!)
L3: sub $1, %rdi
    jnz L3
    inc %rdi
    mov %rdi, %rax
	  ret


	.globl _Z3f2ay
_Z3f2ay:
	# write a function that sums the numbers from 1 to n (which is in %rdi)
	# answers should be returned in %rax
    xor %rcx, %rcx # count up to n
    xor %rax, %rax # holds the final answer
    mov $0, %rcx
L4: inc %rcx
    add %rcx, %rax
    cmp %rcx, %rdi
    jne L4
	  ret

	.globl _Z3f2by
_Z3f2by:
	# write a function that computes n factorial (products 1 to n)
  # mul should automatically values to rax
    xor %rax, %rax # holds product value
    mov $1, %rax
    inc %rdi
L5: 
    sub $1, %rdi 
    mul %rdi
    cmp $1, %rdi
    jne L5
	  ret

