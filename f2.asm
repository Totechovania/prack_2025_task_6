section .text
global f2
f2:
    push ebp
    mov ebp, esp

    finit
    fld qword[ebp + 8]
    fld1
    fld1
    fadd
    fmul
    fld1 
    fld1
    fadd
    fchs
    fadd
    
    mov esp, ebp
    pop ebp
    ret 


