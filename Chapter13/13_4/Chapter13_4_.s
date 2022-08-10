//extern "C" comapareFloat_(float a,float b,bool* results);
//"EQ","NE","GT","LT","GE","LE","U0"
.text
.global comapareFloat_
comapareFloat_:
   fcmpe s0,s1
   
   cset  w1,eq
   strb  w1,[x0]
   cset  w1,ne
   strb  w1,[x0,1]
   cset  w1,gt
   strb  w1,[x0,2]
   cset  w1,mi
   strb  w1,[x0,3]
   cset  w1,ge
   strb  w1,[x0,4]
   cset  w1,ls
   strb  w1,[x0,5]
   cset  w1,vs
   strb  w1,[x0,6]
   ret 
