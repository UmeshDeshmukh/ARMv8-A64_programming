.text
pi:     .double 3.141592653589793
const4: .double 4.0
const3: .double 3.0

.global sphereAreaVol_
sphereAreaVol_:
  ldr d2,const4
  ldr d3,pi
  fmul d1,d0,d0
  fmul d1,d1,d3
  fmul d1,d1,d2
  str  d1,[x0]
  
  ldr d4,const3
  fmul d1,d1,d0
  fdiv d1,d1,d4
  str  d1,[x1]
