//bool corrCoeff_(float* rho,    x0
                //float sum[5],  x1 
                //const float*x, x2
                //const float*y, x3
                //size_t n,      x4
                //float eps);    s0
.text

.macro updateSum REG1,REG2
    fadd v16.4s,v16.4s,\REG1\().4s     //sum(x) 
    fadd v17.4s,v17.4s,\REG2\().4s     //sum(y)
	fmla v18.4s,\REG1\().4s,\REG1\().4s//sum(x*x)
	fmla v19.4s,\REG2\().4s,\REG2\().4s//sum(y*y)
	fmla v20.4s,\REG1\().4s,\REG2\().4s//sum(x*y)
	.endm
	
.macro redToScalar REG
    faddp \REG\().4s,\REG\().4s,\REG\().4s //pairwise across lanes 4->2
	faddp \REG\().4s,\REG\().4s,\REG\().4s //2->1 (scalar value result lower 32 bit)
    .endm	
	
.global corrCoeff_
corrCoeff_:
    eor v16.16b,v16.16b,v16.16b    
    eor v17.16b,v17.16b,v17.16b
    eor v18.16b,v18.16b,v18.16b
    eor v19.16b,v19.16b,v19.16b
	eor v20.16b,v20.16b,v20.16b

L1:	ld1 {v0.4s,v1.4s,v2.4s,v3.4s},[x2],64//x	
	ld1 {v4.4s,v5.4s,v6.4s,v7.4s},[x3],64//y
	
	updateSum v0,v4 
	updateSum v1,v5
	updateSum v2,v6
	updateSum v3,v7
	
	sub x4,x4,16
	cmp x4,16
	b.hs L1
	
sL:	redToScalar v16  //vector-->scalar 
	redToScalar v17  //(sum of elements across lanes)
	redToScalar v18
	redToScalar v19
	redToScalar v20
	
	cbz x4,sL2
	
L2: ldr s1,[x2],16       //load x
    ldr s2,[x3],16       //load y
	fadd s3,s3,s1        //sum(x) 
    fadd s4,s4,s2	     //sum(y)
	fmla s5,s1,v16.4s[0] //sum(x*x)
	fmla s6,s2,v17.4s[0] //sum(y*y)
	fmla s7,s1,v17.4s[0] //sum(x*y)
	subs x4,x4,1
	b.ne L2
	
sL2:stp s3,s4,[x1],8
    stp s5,s6,[x1],8
    str s7,[x1]	
	
	scvtf s8,x4
	fmul  s7,s7,s8 //sum(x*y)*n
	fmul  s9,s3,s4 //sum(x)*sum(y)
	fsub  s7,s7,s9 //sum(x*y)*n - sum(x)*sum(y)
	
	fmul  s5,s5,s8 //sum(x*x)*n
	fmul  s3,s3,s3 //sum(x)*sum(x)
	fsub  s5,s5,s3
	fsqrt s5,s5
	
	fmul  s6,s6,s8 //sum(y*y)*n
	fmul  s4,s4,s4 //sum(y)*sum(y)
	fsub  s6,s6,s3
	fsqrt s6,s6
	
	fmul  s5,s5,s6
	fdiv  s0,s7,s5
//	str   s0,[x0]
        str   s5,[x0]
	mov   w0,1
	ret
	
