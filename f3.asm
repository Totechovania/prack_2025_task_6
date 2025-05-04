section .text
global f3
f3:
    push ebp
    mov ebp, esp

    finit
    fld1 
    fdiv qword[ebp + 8] 
    
    mov esp, ebp
    pop ebp
    ret 

