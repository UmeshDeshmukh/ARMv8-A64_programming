.text 
.global CalQuoRemB_
CalQuoRemB_:
  sdiv x4,x0,x1
  str x4,[x2]

  mul x5,x4,x1    
  sub x6,x0,x5
  str x6,[x3]
  ret

.global CalQuoRemA_
CalQuoRemA_:
  sdiv w4,w0,w1
  str w4,[x2]
  
  mul w5,w4,w1
  sub w6,w0,w5
  str w6,[x3]
  ret
