  .globl f 
f: 
  //rcx hold the value of a and rdx holds the value of b
  xor %rax, %rax
  leaq (%rcx, %rdx), %rax //a+b
  subq %rdx, %rcx //a - b
  imulq %rcx, %rax // rax = rcx * rax
  ret

  .globl makes
mask:
  //rcx holds the value of a and rdx holds the value of b
  xor %rax, %rax
  movq %rcx, %rax // moving a into rax
  andq %rdx, %rax // moving a and b into rax
  cmp %rax, %rdx // comparing rax and rdx
  je jalsdjf
  mov $0, %rax
  ret
jalsdjf:
  mov $1, %rax
  ret

  .globl toggle1
toggle1: 
  //rcx holds the value of a and rdx holds the value of mask
  movq %rcx, %rax // move the value of rcx into rax to return later
  xor %rdx, %rax  // xor the values of rdx(mask) and rax(a)
  ret

  .globl toggle2
toggle2:
  //rcx holds the value of a and rdx holds the value of b
  movq %rcx, %rax //moving the first value a into rax
  cmp %rcx, %rdx //check if a is already equal to b
  je .j2  // if so then just return rax which is already a
.j1:
    inc %rcx //keep increasing rcx and adding it to rax
    addq %rcx, %rax
    cmp %rcx, %rdx 
    jne .j1  //if rcx and rdx are not equal then contiue adding 1 to rcx and adding it to rax
    ret
.j2:
    ret

