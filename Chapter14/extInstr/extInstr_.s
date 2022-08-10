//void extInstr_(Vec128* x,Vec128& a,Vec128& b);
.text
.global extInstr_
extInstr_:
  ldr q1,[x1]
  ldr q2,[x2]
  EXT v0.16b,v1.16b,v2.16b,#6
  str q0,[x0]
  ret
  
//tblInstr_(Vec128* x,Vec128& a,Vec128& b,Vec128& indx);  
.global tblInstr_
tblInstr_:
  ldr q0,[x3]  
  ldr q1,[x1]
  ldr q2,[x2]  
  tbl v3.16b,{v1.16b,v2.16b},v0.16b
  str q3,[x0]
  ret
