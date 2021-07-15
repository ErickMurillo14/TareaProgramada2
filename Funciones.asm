.data
vec1 real4 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0
vec2 real4 9.0,10.0,11.0,12.0,13.0,14.0,15.0,16.0

.code

SumProc proc
    vmovups xmm0, xmmworld ptr [vec1]
    vmovups xmm1, xmmworld ptr [vec2]
    
    vaddps xmm2, xmm0,xmm1
    ret
    
SumProc endp
end

ResProc proc
    vmovups ymm0, ymmworld ptr [vec1]
    vmovups ymm1, ymmworld ptr [vec2]
    vsubps ymm2, ymm0,ymm1
    ret
ResProc endp

DivProc proc 
    vmovups ymm0, ymmworld ptr [vec1]
    vmovups ymm1, ymmworld ptr [vec2]
    vdivps ymm2, ymm0,ymm1
    ret
DivProc endp

MultiProc proc
    vmovups ymm0, ymmworld ptr [vec1]
    vmovups ymm1, ymmworld ptr [vec2]
    vmulps ymm2, ymm0,ymm1
    ret
MultiProc endp

MultiScalarProc proc
    vmovups ymm0, ymmworld ptr [vec1]
    vmovups ymm1, 3.0
    vmulps ymm2, ymm0,ymm1
    ret
MultiProc endp



    