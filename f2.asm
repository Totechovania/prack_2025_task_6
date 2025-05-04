section .data
    consts dq 2., -2.
section .text
global f2
f2:
    push ebp
    mov ebp, esp

    finit
    fld qword[ebp + 8]; a
    fld qword[consts]
    fmul
    fld qword[consts + 8]
    fadd
    
    mov esp, ebp
    pop ebp
    ret 


