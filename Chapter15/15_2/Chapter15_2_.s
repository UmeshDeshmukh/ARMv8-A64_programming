//void packedCompareFloat_(Vec128 x[8], const Vec128& a, const Vec128& b);
.text
.global packedCompareFloat_
packedCompareFloat_:
  ld1 {v1.4s},[x1]
  ld1 {v2.4s},[x2]
  
  fcmeq v0.4s,v1.4s,v2.4s 
  st1  {v0.4s},[x0],16
  not   v0.16b,v0.16b
  st1  {v0.4s},[x0],16
  fcmgt v0.4s,v1.4s,v2.4s
  st1  {v0.4s},[x0],16
  fcmgt v0.4s,v2.4s,v1.4s
  st1  {v0.4s},[x0],16
  fcmge v0.4s,v1.4s,v2.4s
  st1  {v0.4s},[x0],16
  fcmge v0.4s,v2.4s,v1.4s
  st1  {v0.4s},[x0],16
  fcmlt v0.4s,v1.4s,0.0
  st1  {v0.4s},[x0],16
  fcmgt v0.4s,v1.4s,0.0
  st1  {v0.4s},[x0],16
  ret  




//void packedCompareDouble_(Vec128 x[8], const Vec128& a, const Vec128& b);
.global packedCompareDouble_
packedCompareDouble_:
  ld1 {v1.2d},[x1]
  ld1 {v2.2d},[x2]
  
  fcmeq v0.2d,v1.2d,v2.2d
  st1  {v0.2d},[x0],16  
  not   v0.16b,v0.16b
  st1  {v0.2d},[x0],16
  fcmgt v0.2d,v1.2d,v2.2d
  st1  {v0.2d},[x0],16
  fcmgt v0.2d,v2.2d,v1.2d
  st1  {v0.2d},[x0],16
  fcmge v0.2d,v1.2d,v2.2d
  st1  {v0.2d},[x0],16
  fcmge v0.2d,v2.2d,v1.2d
  st1  {v0.2d},[x0],16
  fcmlt v0.2d,v1.2d,0.0
  st1  {v0.2d},[x0],16
  fcmgt v0.2d,v1.2d,0.0
  st1  {v0.2d},[x0],16
  ret 
