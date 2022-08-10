//extern "C" int IntAddSubScalar(int a,int b,int c,int d);
//                                  r0    r1    r2    r3

.text
.global IntAddSubScalar

IntAddSubScalar:
 sub x0,x0,x1       //r0 = a-b
 add x0,x0,x2       //r0 = a-b+c
 sub x0,x0,x3       //r0 = a-b+c-d
 
 bx lr              //return 
