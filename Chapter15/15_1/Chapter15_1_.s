
//void packedMathFloat_(Vec128 x[9],const Vec128& a,const Vec128& b);
.text
.global packedMathFloat_
packedMathFloat_:
  ld1 {v1.4s},[x1]
  ld1 {v2.4s},[x2]
  
  fadd   v0.4s,v1.4s,v2.4s 
  st1   {v0.4s},[x0],16  
  fsub   v0.4s,v1.4s,v2.4s
  st1   {v0.4s},[x0],16
  fmul   v0.4s,v1.4s,v2.4s
  st1   {v0.4s},[x0],16
  fdiv   v0.4s,v1.4s,v2.4s
  st1   {v0.4s},[x0],16
  fabs   v0.4s,v1.4s
  st1   {v0.4s},[x0],16
  fneg   v0.4s,v2.4s
  st1   {v0.4s},[x0],16
  fminnm v0.4s,v1.4s,v2.4s
  st1   {v0.4s},[x0],16
  fmaxnm v0.4s,v1.4s,v2.4s
  st1   {v0.4s},[x0],16
  fsqrt  v0.4s,v1.4s
  st1   {v0.4s},[x0],16
  ret
  

//void packedMathDouble_(Vec128 x[9],const Vec128& a,const Vec128& b);
.global packedMathDouble_
packedMathDouble_: 
  ld1 {v1.2d},[x1]
  ld1 {v2.2d},[x2]
  
  fadd   v0.2d,v1.2d,v2.2d 
  st1   {v0.2d},[x0],16  
  fsub   v0.2d,v1.2d,v2.2d
  st1   {v0.2d},[x0],16
  fmul   v0.2d,v1.2d,v2.2d
  st1   {v0.2d},[x0],16
  fdiv   v0.2d,v1.2d,v2.2d
  st1   {v0.2d},[x0],16
  fabs   v0.2d,v1.2d
  st1   {v0.2d},[x0],16
  fneg   v0.2d,v2.2d
  st1   {v0.2d},[x0],16
  fminnm v0.2d,v1.2d,v2.2d
  st1   {v0.2d},[x0],16
  fmaxnm v0.2d,v1.2d,v2.2d
  st1   {v0.2d},[x0],16
  fsqrt  v0.2d,v1.2d
  st1   {v0.2d},[x0],16
  ret  
