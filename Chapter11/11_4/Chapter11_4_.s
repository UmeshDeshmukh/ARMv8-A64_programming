.data
A1: .word 2,3,5,9,2,4,22,69,0,1
A2: .quad 55,36,-89,-23,11,90

.text
A3: .short -100,200,702,800,999,786,365,666

//int ldrInstrTest1_(unsigned int i,unsigned long j);
//w                            w0              x1 
.global ldrInstrTest1_ 
ldrInstrTest1_:          
  ldr x2,=A1           //A1 array of word(32 bit) size elements
  ldr w3,[x2,w0,uxtw 2]
  ldr w4,[x2,x1,lsl 2] 
  add w0,w3,w4  
  ret
  
  
//long ldrInstrTest2_(unsigned int i,unsigned long j);
//x                            w0              x1     
.global ldrInstrTest2_ 
ldrInstrTest2_:
  ldr x2,=A2           //A2 array of quad(64 bit) size elements
  ldr x3,[x2,w0,uxtw 3]
  ldr x4,[x2,x1,lsl 3]
  add x0,x3,x4
  ret


//short ldrINstrTest3_(unsigned int i,unsigned long j);
//w                            w0              x1

.global ldrInstrTest3_ 
ldrInstrTest3_:
  adr x2,A3           //A3 array of short(16 bit) size elements
  ldrsh w3,[x2,w0,uxtw 1]
  ldrsh w4,[x2,x1,lsl 1]
  add w0,w3,w4
  ret
