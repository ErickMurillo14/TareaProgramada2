.data
vec1 real4 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0
vec2 real4 9.0,10.0,11.0,12.0,13.0,14.0,15.0,16.0

.code

SumProc proc

    ; RCX puntero al primer vector
    ; RDX puntero al segundo vector
    ; R8 puntero vacio para devolver el resultado
	
    ; Se mueve el vector al que apunta RCX hacia el registro xmm0
    ; Se mueve el vector al que apunta RDX hacia el registro xmm1

    vmovups xmm0, [RCX]
    vmovups xmm1, [RDX]
    ; Se realiza la Suma y queda guardada en xmm2
    vaddps xmm2, xmm0,xmm1

    ; Movemos el vector guardado en xmm2 al puntero guardado en r8
	vmovups [r8], xmm2

    ret
    
SumProc endp


RestProc proc
  
    ; RCX puntero al primer vector
    ; RDX puntero al segundo vector
    ; R8 puntero vacio para devolver el resultado
	
    ; Se mueve el vector al que apunta RCX hacia el registro xmm0
    ; Se mueve el vector al que apunta RDX hacia el registro xmm1

    vmovups xmm0, [RCX]
    vmovups xmm1, [RDX]
    ; Se realiza la Resta y queda guardada en xmm2
    vsubps xmm2, xmm0,xmm1

    ; Movemos el vector guardado en xmm2 al puntero guardado en r8
	vmovups [r8], xmm2

    ret
RestProc endp

DivProc proc 
    
    ; RCX puntero al primer vector
    ; RDX puntero al segundo vector
    ; R8 puntero vacio para devolver el resultado
	
    ; Se mueve el vector al que apunta RCX hacia el registro xmm0
    ; Se mueve el vector al que apunta RDX hacia el registro xmm1

    vmovups xmm0, [RCX]
    vmovups xmm1, [RDX]
    ; Se realiza la Division y queda guardada en xmm2
    vdivps xmm2, xmm0,xmm1

    ; Movemos el vector guardado en xmm2 al puntero guardado en r8
	vmovups [r8], xmm2

    ret
DivProc endp

MultiProc proc
    
    ; RCX puntero al primer vector
    ; RDX puntero al segundo vector
    ; R8 puntero vacio para devolver el resultado
	
    ; Se mueve el vector al que apunta RCX hacia el registro xmm0
    ; Se mueve el vector al que apunta RDX hacia el registro xmm1

    vmovups xmm0, [RCX]
    vmovups xmm1, [RDX]
    ; Se realiza la multiplicacion y queda guardada en xmm2
    vmulps xmm2, xmm0,xmm1

    ; Movemos el vector guardado en xmm2 al puntero guardado en r8
	vmovups [r8], xmm2

    ret
MultiProc endp


MultiScalarProc proc
    ; Recibe en xmm0 el escalar
    ; Recibe en RDX el puntero al vector
    ; Recibe en R8 el puntero para guardar el resultado

    ; Reserva memoria en el puntero resultado
    ; ebx =
    mov rax, 0

    ; Cantidad de elementos
    mov edx, 4
    ; Reserva espacio en el puntero
    vmovups xmm2, [RDX]

    vmovups [r8], xmm2

    ; Guardamos el escalar para no perderlo al utilizar mulss
    
loop: 
        vmovups xmm2, xmm0
        movss xmm1, [RDX + RAX*4]
        MULSS xmm1, xmm2
        movss [R8 + RAX*4] , xmm2 ; TODO: Arreglar esta parte
        
		dec edx
		jz done
		inc eax
		jmp loop
done:
    ret
MultiScalarProc endp

end


sumArr proc 
	;En ecx queda el arreglo 
	;En edx queda la cantidad de elementos
	;se retorna el resultado en eax 
	;RCX y RAX son registros de 64 bits
	;Deben tener cuidado de donde quedan los arguementos que envian desde c++.
	mov ebx, 0
	mov eax, 0
	suma: 
		add ebx, [RCX + RAX * 4]
		dec edx
		jz done
		inc eax
		jmp suma
	done:
		mov eax, 0 
		mov eax, ebx
	ret 
sumArr endp

;TODO: Implementar la funcion adicional: elevar al cuadrado,  
ELevar al cuadrado proc
    
    ; RCX puntero al primer vector
    ; RDX puntero al segundo vector
    ; R8 puntero vacio para devolver el resultado
	
    ; Se mueve el vector al que apunta RCX hacia el registro xmm0
    ; Se mueve el vector al que apunta RDX hacia el registro xmm1

    vmovups xmm0, [RCX]
    vmovups xmm1, [RDX]; metiendo aqui el rcx
    ; Se realiza la multiplicacion y queda guardada en xmm2
    vmulps xmm2, xmm0,xmm1

    ; Movemos el vector guardado en xmm2 al puntero guardado en r8
	vmovups [r8], xmm2

    ret

    