

.data
vec1 real4 1.0,2.0
vec2 real4 9.0,10.0,11.0
.code


SumProc proc
	
    vmovups xmm0, xmmword ptr [vec1]
    vmovups xmm1, xmmword ptr [vec2]
    
    vaddps xmm2, xmm0,xmm1

	vmovups xmm0, xmm2
	vmovups [rcx], xmm2

	mov rax,rcx
    ret
    
SumProc endp
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

end