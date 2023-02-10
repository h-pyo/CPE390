#"I pledge my honor that I have abided by the Stevens Honor System." - Harris Pyo
# Partner: Justin Chen
  .globl    main
main:
    mov     $3, %rcx
    mov     $1, %rdx
    mov     $1, %rsi
    call        maskandcompare
    mov     $3, %rcx
    mov     $1, %rdx 
    mov     $0, %rsi 
    call    maskandcompare
    mov     $16, %rcx
    mov     $15, %rdx
    mov     $0, %rsi
    call    maskandcompare
    ret
maskandcompare:
    mov %rcx, %r8
    and %rdx, %r8
    cmp %rsi, %r8
    je true
    mov $0, %rax
    ret
true:
    mov     $1, %rax 
    ret
