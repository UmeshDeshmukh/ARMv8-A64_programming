//int IntMulScalarA_(int a,int b);
.text
.global IntMulScalarA_
IntMulScalarA_:
  mul w0,w0,w1
  ret

.global LongMulScalarB_
LongMulScalarB_:
  mul x0,x0,x1
  ret

.global LongMulScalarC_
LongMulScalarC_:
  smull x0,w0,w1
  ret

.global LongMulScalarD_
LongMulScalarD_:
  umull x0,w0,w1 
 
