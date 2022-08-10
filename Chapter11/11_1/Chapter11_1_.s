//extern "C" int IntAddSubScalar_(int a,int b,int c,int d);
//                                  x0    x1    x2    x3

.text
.global IntAddSubScalar_

IntAddSubScalar_:
 sub x0,x0,x1       //r0 = a-b
 add x0,x0,x2       //r0 = a-b+c
 sub x0,x0,x3       //r0 = a-b+c-d
 
 ret                //return 

//extern "C" long IntAddSubScalar2_(long a,long b,long c,long d)








