.text 
constFtoC: .single 0.5555556
constCtoF: .single 1.8
constConv: .single 32.0

.global cvtFtoC_
cvtFtoC_:
  ldr s1,constConv
  fsub s0,s0,s1
  ldr s2,constFtoC
  fmul s0,s0,s2
  ret
  
.global cvtCtoF_
cvtCtoF_:
  ldr s1,constCtoF
  fmul s0,s0,s1
  ldr s2,constConv
  fadd s0,s0,s2
  ret
  
