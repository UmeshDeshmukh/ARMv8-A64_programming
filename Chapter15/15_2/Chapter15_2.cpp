#include<iostream>
#include<iomanip>
#include<cmath>
#include "Vec128.h"

using namespace std;
extern "C" void packedCompareFloat_(Vec128 x[8], const Vec128& a, const Vec128& b);
extern "C" void packedCompareDouble_(Vec128 x[8], const Vec128& a, const Vec128& b);

const char* cmpOps[] = {"EQ","NE","GT","LT","GE","LE","a LT0","b GT0"};

int main(){
	Vec128 result1[9],result2[9],a1,b1,a2,b2;
	
	a1.m_F32[0]= 0.333f;      b1.m_F32[0]= -999999999.9f;
	a1.m_F32[1]= 3.1423f;     b1.m_F32[1]= 1067.6633f;
	a1.m_F32[2]= 9.999f;      b1.m_F32[2]= -111.111111f;
	a1.m_F32[3]= 0.0000001f;  b1.m_F32[3]= 100000000.1f;
	packedCompareFloat_(result1,a1,b1);
	cout<<"Packed float math result:"<<endl;
	cout<<"a: "        <<a1.ToStringF32()<<endl;
	cout<<"b: "        <<b1.ToStringF32()<<endl;
	cout<<"EQ: "   <<result1[0].ToStringF32()<<endl;
	cout<<"NE: "   <<result1[1].ToStringF32()<<endl;
	cout<<"GT: "   <<result1[2].ToStringF32()<<endl;
	cout<<"LT: "   <<result1[3].ToStringF32()<<endl;
	cout<<"GE: "<<result1[4].ToStringF32()<<endl;
	cout<<"LE: "<<result1[5].ToStringF32()<<endl;
	cout<<"LT0: " <<result1[6].ToStringF32()<<endl;
	cout<<"GT0: " <<result1[7].ToStringF32()<<endl;
		
	a2.m_F64[0]= 55555555555.333;b2.m_F64[0]= 999999999.9;
	a2.m_F64[1]= 3.1423;         b2.m_F64[1]= -1067.6633;
	packedCompareDouble_(result2,a2,b2);
	cout<<"Packed float math result:"<<endl;
	cout<<"a: "<<a2.ToStringF64()<<endl;
	cout<<"b: "<<b2.ToStringF64()<<endl;
	cout<<"EQ: "<<result2[0].ToStringF64()<<endl;
	cout<<"NE: "<<result2[1].ToStringF64()<<endl;
	cout<<"GT: "<<result2[2].ToStringF64()<<endl;
	cout<<"LT: "<<result2[3].ToStringF64()<<endl;
	cout<<"GE: "<<result2[4].ToStringF64()<<endl;
	cout<<"LE: "<<result2[5].ToStringF64()<<endl;
	cout<<"LT0:"<<result2[6].ToStringF64()<<endl;
	cout<<"GT0:"<<result2[7].ToStringF64()<<endl;
		
	return 0;
}
