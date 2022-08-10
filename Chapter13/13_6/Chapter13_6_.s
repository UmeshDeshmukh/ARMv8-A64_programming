//extern "C" void meanStdev_(double* mean,     x0
//                           double* stdev,    x1  
//					         const double* x,  x2
//					         int n);           w3    

.text
.global meanStdev_
meanStdev_:
  movi  d0,0
  mov  w5,0
  mov  x4,x2
  //calculate mean
L1: ldr  d1,[x4],8
    fadd d0,d0,d1
    add  w5,w5,1
    cmp  w5,w3
    b.lt L1
	
	scvtf d5,w3
	fdiv  d0,d0,d5
	str   d0,[x0]
	
	movi  d0,0
    mov  w5,0
    mov  x4,x2
//Calculate standard deviation
    ldr d1,[x0]
L2: ldr d2,[x4],8 	
	fsub d2,d2,d1 
	fmadd d0,d2,d2,d0
	cmp  w5,w3
    b.lt L2
	
	sub w3,w3,1
	scvtf d5,w3
	fdiv d0,d0,d5
	fsqrt d0,d0
	str  d0,[x1]
	ret
     
	
	
