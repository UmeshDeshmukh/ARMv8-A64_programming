#include<iostream>
#include<string>
#include "Vec128.h"

using namespace std;
extern "C" void packedAddI16_(Vec128* x,Vec128& a,Vec128& b);
extern "C" void packedSubI16_(Vec128* x,Vec128& a,Vec128& b);
extern "C" void packedAddU16_(Vec128* x,Vec128& a,Vec128& b);
extern "C" void packedSubU16_(Vec128* x,Vec128& a,Vec128& b);

int main(int argc,char** argv){
	Vec128 x[2],a,b;
	a.m_I16[0]= 100; b.m_I16[0]= -140;
	a.m_I16[1]= -110; b.m_I16[1]= 544;
	a.m_I16[2]= 524; b.m_I16[2]= -322;
	a.m_I16[3]= 719; b.m_I16[3]= 154;
	a.m_I16[4]= -98; b.m_I16[4]= 654;
	a.m_I16[5]= 607; b.m_I16[5]= -125;
	a.m_I16[6]= 270; b.m_I16[6]= 784;
	a.m_I16[7]= -999; b.m_I16[7]= -022;
	packedAddI16_(x,a,b);
	cout<<"Wraparound addition I16 result:"<<endl;
	cout<<"a:    "<<a.ToStringI16()<<endl;
	cout<<"b:    "<<b.ToStringI16()<<endl;
	cout<<"x[0]: "<<x[0].ToStringI16()<<endl;
	cout<<"Saturated addition I16 result:"<<endl;
	cout<<"a:    "<<a.ToStringI16()<<endl;
	cout<<"b:    "<<b.ToStringI16()<<endl;
	cout<<"x[0]: "<<x[0].ToStringI16()<<endl;
	
	a.m_I16[0]= 1380; b.m_I16[0]= -1440;
	a.m_I16[1]= -3810; b.m_I16[1]= 5444;
	a.m_I16[2]= 5384; b.m_I16[2]= -3422;
	a.m_I16[3]= 7789; b.m_I16[3]= 1544;
	a.m_I16[4]= -7898; b.m_I16[4]= 6454;
	a.m_I16[5]= 6787; b.m_I16[5]= -1425;
	a.m_I16[6]= 2820; b.m_I16[6]= 7844;
	a.m_I16[7]= -8299; b.m_I16[7]= -4022;
	packedSubI16_(x,a,b);
	cout<<"Wraparound subtraction I16 result:"<<endl;
	cout<<"a:    "<<a.ToStringI16()<<endl;
	cout<<"b:    "<<b.ToStringI16()<<endl;
	cout<<"x[0]: "<<x[0].ToStringI16()<<endl;
	cout<<"Saturated subtraction I16 result:"<<endl;
	cout<<"a:    "<<a.ToStringI16()<<endl;
	cout<<"b:    "<<b.ToStringI16()<<endl;
	cout<<"x[0]: "<<x[0].ToStringI16()<<endl;
	
	a.m_U16[0]= 1380;  b.m_U16[0]= 1740;
	a.m_U16[1]= 3810;  b.m_U16[1]= 5744;
	a.m_U16[2]= 5384;  b.m_U16[2]= 3421;
	a.m_U16[3]= 7789;  b.m_U16[3]= 1541;
	a.m_U16[4]= 7898;  b.m_U16[4]= 6451;
	a.m_U16[5]= 6787;  b.m_U16[5]= 1925;
	a.m_U16[6]= 2820;  b.m_U16[6]= 7944;
	a.m_U16[7]= 8299;  b.m_U16[7]= 4922;
	
	packedAddU16_(x,a,b);
	cout<<"Wraparound Addition U16 result:"<<endl;
	cout<<"a:    "<<a.ToStringU16()<<endl;
	cout<<"b:    "<<b.ToStringU16()<<endl;
	cout<<"x[0]: "<<x[0].ToStringU16()<<endl;
	cout<<"Saturated Addition U16 result:"<<endl;
	cout<<"a:    "<<a.ToStringU16()<<endl;
	cout<<"b:    "<<b.ToStringU16()<<endl;
	cout<<"x[0]: "<<x[0].ToStringU16()<<endl;
	
	packedSubU16_(x,a,b);
	cout<<"Wraparound subtraction U16 result:"<<endl;
	cout<<"a:    "<<a.ToStringU16()<<endl;
	cout<<"b:    "<<b.ToStringU16()<<endl;
	cout<<"x[0]: "<<x[0].ToStringU16()<<endl;
	cout<<"Saturated subtraction U16 result:"<<endl;
	cout<<"a:    "<<a.ToStringU16()<<endl;
	cout<<"b:    "<<b.ToStringU16()<<endl;
	cout<<"x[0]: "<<x[0].ToStringU16()<<endl;
	return 0;
}
