//extern "C" void local_Var_(int32_t a,
//                           int32_t b,
//                           int32_t c,
//						     int32_t d,
//						     int64_t e,
//                           int64_t f,
//                           int64_t g,
//                           int64_t h,
//                           int32_t*x, 
//                           int64_t*y );

//offsets for local variables
.equ t0,0 
.equ t1,4
.equ t2,8
.equ t3,16
.equ locVarSize,32
.equ argX,48
.equ argY,56
.text
.global local_Var_
local_Var_:
// 	int32_t t0 = a+b-c;
//	int32_t t1 = d+global_var2;
//  int64_t t2 = e-f+g;
//  int64_t t3 = h-global_var1;
//  *x = t0*t1;
//  *y = t2*t3;	
	
    //prologue	
	stp x19,x20,[SP,-16]!
	sub SP,SP,locVarSize
	
	add w0,w0,w1
	sub w0,w0,w2
	str w0,[SP,t0]
		
	ldr x19,=global_var2
	ldr w19,[x19]
	add w19,w3,w19
	str w19,[SP,t1]
				
	sub x4,x4,x5
	add x4,x4,x6
	str x4,[SP,t2]
	
	ldr x20,=global_var1
	ldr x20,[x20]
	sub x7,x7,x20
	str x7,[SP,t3]
	
    ldr w0,[SP,t0]
    ldr w1,[SP,t1]
	mul w0,w0,w1
	ldr x3,[SP,argX]
	str w0,[x3]
	
	ldr x0,[SP,t2]
    ldr x1,[SP,t3]
	mul x0,x0,x1
	ldr x3,[SP,argY]
	str x0,[x3]
	
	add SP,SP,locVarSize
	ldp x19,x20,[SP],16
	ret
