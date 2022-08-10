#include<iostream>
#include<cstdint>
#include<iomanip>
#include<cmath>
#include<limits>
#include "Vec128.h"

using namespace std;
extern "C" void packedMathFloat_(Vec128 x[9],const Vec128& a,const Vec128& b);
extern "C" void packedMathDouble_(Vec128 x[9],const Vec128& a,const Vec128& b);

int main()
{
	Vec128 result1[9],result2[9],a1,b1,a2,b2;
	
	a1.m_F32[0]= 0.333f;      b1.m_F32[0]= -999999999.9f;
	a1.m_F32[1]= 3.1423f;     b1.m_F32[1]= 1067.6633f;
	a1.m_F32[2]= 9.999f;      b1.m_F32[2]= -111.111111f;
	a1.m_F32[3]= 0.0000001f;  b1.m_F32[3]= 100000000.1f;
	
	packedMathFloat_(result1,a1,b1);
		
	cout<<"Packed float math result:"<<endl;
	cout<<"a: "        <<a1.ToStringF32()<<endl;
	cout<<"b: "        <<b1.ToStringF32()<<endl;
	cout<<"fadd: "   <<result1[0].ToStringF32()<<endl;
	cout<<"fsub: "   <<result1[1].ToStringF32()<<endl;
	cout<<"fmul: "   <<result1[2].ToStringF32()<<endl;
	cout<<"fdiv: "   <<result1[3].ToStringF32()<<endl;
	cout<<"fabs(b): "<<result1[4].ToStringF32()<<endl;
	cout<<"fneg(a): "<<result1[5].ToStringF32()<<endl;
	cout<<"fminnm: " <<result1[6].ToStringF32()<<endl;
	cout<<"fmaxnm: " <<result1[7].ToStringF32()<<endl;
	cout<<"fsqrt: "  <<result1[8].ToStringF32()<<endl;
	
	a2.m_F64[0]= 55555555555.333;b2.m_F64[0]= 999999999.9;
	a2.m_F64[1]= 3.1423;         b2.m_F64[1]= -1067.6633;
	
	packedMathDouble_(result2,a2,b2);
	
	cout<<"Packed double math result:"<<endl;
	cout<<"a: "        <<a2.ToStringF64()<<endl;
	cout<<"b: "        <<b2.ToStringF64()<<endl;
	cout<<"fadd: "   <<result2[0].ToStringF64()<<endl;
	cout<<"fsub: "   <<result2[1].ToStringF64()<<endl;
	cout<<"fmul: "   <<result2[2].ToStringF64()<<endl;
	cout<<"fdiv: "   <<result2[3].ToStringF64()<<endl;
	cout<<"fabs(b): "<<result2[4].ToStringF64()<<endl;
	cout<<"fneg(a): "<<result2[5].ToStringF64()<<endl;
	cout<<"fminnm: " <<result2[6].ToStringF64()<<endl;
	cout<<"fmaxnm: " <<result2[7].ToStringF64()<<endl;
	cout<<"fsqrt: "  <<result2[8].ToStringF64()<<endl;
		
	return 0;
}

