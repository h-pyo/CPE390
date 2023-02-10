# "I pledge my honor that I have abided by the Stevens Honor System."" - Harris Pyo
# Parter: Justin Chen
  .globl main
main:
	mov	$6, %rcx
	mov	$7, %rdx
	call	f
	ret

  .global f
f: 
  lea (%rcx, %rdx), %rax
  shr $1, %rax
  ret
