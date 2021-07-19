.data

.code

SumProc proc

    ; RCX puntero al primer vector
    ; RDX puntero al segundo vector
    ; R8 puntero vacio para devolver el resultado
	
    ; Se mueve el vector al que apunta RCX hacia el registro xmm0
    ; Se mueve el vector al que apunta RDX hacia el registro xmm1

    vmovups ymm0, [RCX]
    vmovups ymm1, [RDX]
    ; Se realiza la Suma y queda guardada en xmm2
    vaddps ymm2, ymm0,ymm1

    ; Movemos el vector guardado en xmm2 al puntero guardado en r8
	vmovups [r8], ymm2

    ret
    
SumProc endp


RestProc proc
  
    ; RCX puntero al primer vector
    ; RDX puntero al segundo vector
    ; R8 puntero vacio para devolver el resultado
	
    ; Se mueve el vector al que apunta RCX hacia el registro xmm0
    ; Se mueve el vector al que apunta RDX hacia el registro xmm1

    vmovups ymm0, [RCX]
    vmovups ymm1, [RDX]
    ; Se realiza la Resta y queda guardada en xmm2
    vsubps ymm2, ymm0,ymm1

    ; Movemos el vector guardado en xmm2 al puntero guardado en r8
	vmovups [r8], ymm2

    ret
RestProc endp

DivProc proc 
    
    ; RCX puntero al primer vector
    ; RDX puntero al segundo vector
    ; R8 puntero vacio para devolver el resultado
	
    ; Se mueve el vector al que apunta RCX hacia el registro xmm0
    ; Se mueve el vector al que apunta RDX hacia el registro xmm1

    vmovups ymm0, [RCX]
    vmovups ymm1, [RDX]
    ; Se realiza la Division y queda guardada en xmm2
    vdivps ymm2, ymm0,ymm1

    ; Movemos el vector guardado en xmm2 al puntero guardado en r8
	vmovups [r8], ymm2

    ret
DivProc endp

MultiProc proc
    
    ; RCX puntero al primer vector
    ; RDX puntero al segundo vector
    ; R8 puntero vacio para devolver el resultado
	
    ; Se mueve el vector al que apunta RCX hacia el registro xmm0
    ; Se mueve el vector al que apunta RDX hacia el registro xmm1

    vmovups ymm0, [RCX]
    vmovups ymm1, [RDX]
    ; Se realiza la multiplicacion y queda guardada en xmm2
    vmulps ymm2, ymm0, ymm1

    ; Movemos el vector guardado en xmm2 al puntero guardado en r8
	vmovups [r8], ymm2

    ret
MultiProc endp


MultiScalarProc proc
    ; Recibe en xmm0 el escalar
    ; Recibe en RDX el puntero al vector
    ; Recibe en R8 el puntero para guardar el resultado

    ; Reserva memoria en el puntero resultado
     
    mov rax, 0

    ; Cantidad de elementos
    mov ebx, 8


    ; Reserva espacio en el puntero
    vmovups xmm2, [RDX]

    vmovups [R8], xmm2
    

    ; Guardamos el escalar para no perderlo al utilizar mulss
     vmovups xmm2, xmm0
    loop1:
       
        vmovss xmm1, DWORD PTR[RDX + 4 * RAX]

        mulss xmm1, xmm2
        vmovss DWORD PTR[R8 + RAX*4] , xmm1 ; TODO: Arreglar esta parte
        
		dec ebx
		jz done
		inc eax
		jmp loop1
done:
    ret
MultiScalarProc endp




    SquareProc proc
    
    ; RCX puntero al primer vector
    ; RDX puntero vacio para devolver el resultado
	
    ; Se mueve el vector al que apunta RCX hacia el registro xmm0
    ; Se mueve el vector al que apunta RCX hacia el registro xmm1

    vmovups ymm0, [RCX]
    vmovups ymm1, [RCX]; metiendo aqui el rcx
    ; Se realiza la multiplicacion y queda guardada en xmm2
    vmulps ymm2, ymm0, ymm1

    ; Movemos el vector guardado en xmm2 al puntero guardado en RDX
	vmovups [RDX], ymm2

    ret
    SquareProc endp

end
