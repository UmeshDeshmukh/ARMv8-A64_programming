//extern "C" int64_t sumOfCubes_( 
//                               uint64_t a, 0
//                               uint32_t b, 1
//                               uint8 _t c, 2
//                               uint16_t d, 3
//                                int16_t e, 4
//                                int8 _t f, 5
//                                int32_t g, 6
//                                int64_t h, 7
//                                int32_t i, 8
//                               uint32_t j);9

.text
.global sumOfCubes_
sumOfCubes_: 
   	 //a*a*a
   	 mul x10,x0,x0   //a*a
   	 mul x10,x10,x0  //a*a*a 

   	 uxtw x1,w1
   	 mul x11,x1,x1
   	 madd x10,x11,x1,x10	
	
	uxtb x2,w2
	mul x11,x2,x2
	madd x10,x11,x2,x10
	
	uxth x3,w3
	mul x11,x3,x3
	madd x10,x11,x3,x10
	
        sxth x4,w4 //sign extend 
	mul x11,x4,x4
	madd x10,x11,x4,x10
	
	sxtb x5,w5            
	mul x11,x5,x5
	madd x10,x11,x5,x10
	
	sxtw x6,w6
	mul x11,x6,x6
	madd x10,x11,x6,x10
	
	mul x11,x7,x7
	madd x10,x11,x7,x10
	
	ldrsw x8,[SP,0]
	ldr x9,[SP,8]
	
	sxtw x8,w8
	mul x11,x8,x8
	madd x10,x11,x8,x10
	
	uxtw x9,w9
	mul x11,x9,x9
	madd x0,x11,x9,x10
	ret
