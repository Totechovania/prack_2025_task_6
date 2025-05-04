section .text
global f1
f1:
    push ebp
    mov ebp, esp

    finit
    fldl2e ; log_2 e
    fchs; log_2 e^-1
    fmul qword[ebp + 8] ; log_2 e^-x
    fld st0 ; log_2 e^-x : log_2 e^-x
    fld1 ; 1 : log_2 e^-x : log_2 e^-x
    fxch ; log_2 e^-x : 1 : log_2 e^-x
    fprem ; {log_2 e^-x} : 1 : log_2 e^-x
    f2xm1 ; 2^{log_2 e^-x} - 1 : 1 : log_2 e^-x
    fadd ; 2^{log_2 e^-x} : log_2 e^-x
    fscale ; 2^({log_2 e^-x} + [log_2 e^-x]) = 2^(log_2 e^-x) = e^-x

    fld1
    fld1
    fld1
    fadd
    fadd
    fadd

    
    mov esp, ebp
    pop ebp
    ret 
