//extern "C" bool compareA_(int32_t a,int32_t b,int32_t c,int32_t* sum);
.text
.global compareA_
compareA_:
	add w0,w0,w1	
    add w0,w0,w2
	str w0,[x3]
	
	cmp w0,100
    b.ge GrTEq
    mov w0,#0	
	ret
GrTEq:	
	mov w0,#1
	ret

//extern "C" bool compareC_(int32_t a,int32_t b,int32_t c,int32_t* sum);

.global compareC_
compareC_:
    adds w0,w0,w1
	cset w4,vs
	adds w0,w0,w2
	cset w5,vs
	str w0,[x3]
	orr w0,w4,w5
	ret

//extern "C" bool compareB_(int64_t a,int64_t b,int64_t c,int64_t* sum);

.global compareB_
compareB_:
    adds x0,x0,x1
	adds x0,x0,x2
	str x0,[x3]
	b.gt gtZ
	mov w0,#0
	ret
gtZ:
    mov w0,#1	
	ret
