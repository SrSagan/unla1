.section .rodata
.globl hello
hello:
  .string "Un grande el martin!"

.text
.global main

main:
  push %rbp
  mov %rsp, %rbp #createa  stack frame

  mov $hello, %edi #put the adress of hello into RDI
  call puts

  mov $0, %eax #return value = 0 normally eax eax
  leave
  ret
