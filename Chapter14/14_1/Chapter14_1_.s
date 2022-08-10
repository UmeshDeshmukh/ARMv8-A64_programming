//void packedAddI16_(Vec128* x,Vec128& a,Vec128& b);
.text
.global packedAddI16_
packedAddI16_:
  ldr q1,[x1]
  ldr q2,[x2]
  add v0.8h,v1.8h,v2.8h
  str q0,[x0]
  
  sqadd v0.8h,v1.8h,v2.8h
  str q0,[x0,16]
  ret
  
//void packedSubI16_(Vec128* x,Vec128& a,Vec128& b);
.global packedSubI16_
packedSubI16_:
  ldr q1,[x1]
  ldr q2,[x2]
  sub v0.8h,v1.8h,v2.8h
  str q0,[x0]
  
  sqsub v0.8h,v1.8h,v2.8h
  str q0,[x0,16]
  ret
  
//void packedAddU16_(Vec128* x,Vec128& a,Vec128& b);
.global packedAddU16_
packedAddU16_:
  ld1 {v1.8h},[x1]
  ld1 {v2.8h},[x2]
  add v3.8h,v1.8h,v2.8h
  //st1 {v0.8h},[x0]
    
  uqadd v4.8h,v1.8h,v2.8h
  st1 {v3.8h,v4.8h},[x0]
  ret  
  
//void packedSubU16_(Vec128* x,Vec128& a,Vec128& b);
.global packedSubU16_
packedSubU16_:
  ld1 {v1.8h},[x1]
  ld1 {v2.8h},[x2]
  sub v3.8h,v1.8h,v2.8h
  //st1 {v0.8h},[x0]
    
  uqsub v4.8h,v1.8h,v2.8h
  st1 {v3.8h,v4.8h},[x0]  
  ret
