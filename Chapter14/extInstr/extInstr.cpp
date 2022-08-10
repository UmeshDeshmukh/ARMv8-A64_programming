#include<iostream>
#include<string>
#include "Vec128.h"

using namespace std;
extern "C" void extInstr_(Vec128* x,Vec128& a,Vec128& b);
extern "C" void tblInstr_(Vec128* x,Vec128& a,Vec128& b,Vec128& indx);
Vec128 a,b,indx,x,y,a2,b2;
int main(){
	
	a.m_U16[0] = 0; //b.m_U16[7] = 0;
	a.m_U16[1] = 1; //b.m_U16[6] = 1;
	a.m_U16[2] = 2; //b.m_U16[5] = 2;
	a.m_U16[3] = 3; //b.m_U16[4] = 3;
	a.m_U16[4] = 4; //b.m_U16[3] = 4;
	a.m_U16[5] = 5; //b.m_U16[2] = 5;
	a.m_U16[6] = 6; //b.m_U16[1] = 6;
	a.m_U16[7] = 7; //b.m_U16[0] = 7;
	
	b.m_U16[7] = 15;
	b.m_U16[6] = 14;
	b.m_U16[5] = 13;
	b.m_U16[4] = 12;
	b.m_U16[3] = 11;
	b.m_U16[2] = 10;
	b.m_U16[1] = 9;
	b.m_U16[0] = 8;
	
	indx.m_U8[0] = 0*2;indx.m_U8[8]  = 16;
    indx.m_U8[1] = 1*2;indx.m_U8[9]  = 18;
    indx.m_U8[2] = 2*2;indx.m_U8[10] = 20;
    indx.m_U8[3] = 3*2;indx.m_U8[11] = 22;
    indx.m_U8[4] = 4*2;indx.m_U8[12] = 24;
    indx.m_U8[5] = 5*2;indx.m_U8[13] = 26;
	indx.m_U8[6] = 6*2;indx.m_U8[14] = 28;
	indx.m_U8[7] = 7*2;indx.m_U8[15] = 30;
	
	a2.m_U8[0] = 0*2;a2.m_U8[8]  = 8*2;
    a2.m_U8[1] = 1*2;a2.m_U8[9]  = 9*2;
    a2.m_U8[2] = 2*2;a2.m_U8[10] = 10*2;
    a2.m_U8[3] = 3*2;a2.m_U8[11] = 11*2;
    a2.m_U8[4] = 4*2;a2.m_U8[12] = 12*2;
    a2.m_U8[5] = 5*2;a2.m_U8[13] = 13*2;
	a2.m_U8[6] = 6*2;a2.m_U8[14] = 14*2;
	a2.m_U8[7] = 7*2;a2.m_U8[15] = 15*2;

	b2.m_U8[0] = 0*3;b2.m_U8[8]  =  8*3;
    b2.m_U8[1] = 1*3;b2.m_U8[9]  =  9*3;
    b2.m_U8[2] = 2*3;b2.m_U8[10] = 10*3;
    b2.m_U8[3] = 3*3;b2.m_U8[11] = 11*3;
    b2.m_U8[4] = 4*3;b2.m_U8[12] = 12*3;
    b2.m_U8[5] = 5*3;b2.m_U8[13] = 13*3;
	b2.m_U8[6] = 6*3;b2.m_U8[14] = 14*3;
	b2.m_U8[7] = 7*3;b2.m_U8[15] = 15*3;	
	
	extInstr_(&x,a,b);
	cout<<"EXT instruction result:"<<endl;
	cout<<"x[0]: "<<x.ToStringU16()<<endl;
	
	tblInstr_(&y,a2,b2,indx);
	cout<<"TBL instruction result:"<<endl;
	cout<<"y: "<<y.ToStringU8()<<endl;
	return 0;
}
