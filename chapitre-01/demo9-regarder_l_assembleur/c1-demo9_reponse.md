main:
pushq %rbp
movq %rsp, %rbp
subq $16, %rsp
movl $0, -4(%rbp)
leaq .L.str(%rip), %rdi
movb $0, %al
callq printf@PLT
xorl %eax, %eax
addq $16, %rsp
popq %rbp
retq
.L.str:
.asciz "Bonjour\n"
