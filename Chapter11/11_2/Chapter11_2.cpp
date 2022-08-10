
#include<iostream>
#include<cstdint>

using namespace std;

extern "C" int IntMulScalarA_(int a,int b);
extern "C" long LongMulScalarB_(long a,long b);
extern "C" long LongMulScalarC_(int a,int b);
extern "C" unsigned long LongMulScalarD_(unsigned int a,unsigned int b);

template<typename T1,typename T2>
void PrintResult1(const char* str,T1 a,T1 b,T2 result){
        cout<<str<<endl;
        cout<<"a = "<< a <<endl;
        cout<<"b = "<< b <<endl;
        cout<<"result = "<< result <<endl;
        cout<<endl;
        }

int main(int argc,char** argv){
        int a,b,result1;
        long c,d,result2;
        unsigned long e,f,result3;
        unsigned int g,h;
        a = 12;
        b = 25;
        
        g = 255;
        h = 255;
        result1 = IntMulScalarA_(a,b);
//        PrintResult1("Result 1:",a,b,result1);
        a = 220;
        b = 550;
        c = 98999999999;
        d = -71456789964;
        result2 = LongMulScalarB_(c,d);
//        PrintResult1("Result 2:",c,d,result2);
        result2 = LongMulScalarC_(a,b);
//        PrintResult1("Result 3:",a,b,result2);
        result3 = LongMulScalarD_(g,h);
//        PrintResult1("Result 4:",g,h,result3);
        
        }













^G Help        ^O Write Out   ^W Where Is    ^K Cut         ^T Execute     ^C Location
^X Exit        ^R Read File   ^\ Replace     ^U Paste       ^J Justify     ^_ Go To Line


template<type T1,type T2>
void PrintResult(const char* str,T1 a,T1 b,T2 result){
	cout<<str<<endl;
	cout<<"a = "<< a <<endl;
	cout<<"b = "<< b <<endl;
	cout<<"result = "<< result <<endl;
	cout<<endl;
	}

int main(int argc,char** argv){
	int a,b,c,d,result;
	a = 12;
	b = 25; 
	c = 88;
	d = 31;
	result = IntAddSubScalar_(a,b,c,d);
	PrintResult("Result 1:",a,b,c,d,result);
	a = 22;
	b = 55; 
	c = 98;
	d = 71;
	result = IntAddSubScalar_(a,b,c,d);
	PrintResult("Result 2:",a,b,c,d,result);
	}
