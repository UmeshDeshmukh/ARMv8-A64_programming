#include<iostream>

using namespace std;

extern "C" int IntAddSubScalar(int a,int b,int c,int d);

void PrintResult(const char* str,int a,int b,int c,int d,int result){
	cout<<str<<endl;
	cout<<"a = "<<endl;
	cout<<"b = "<<endl;
	cout<<"c = "<<endl;
	cout<<"d = "<<endl;
	cout<<"result = "<<endl;
	cout<<endl;
	}

int main(int argc,char** argv){
	int a,b,c,d,result;
	a = 12;
	b = 25; 
	c = 88;
	d = 31;
	result = IntAddSubScalar(a,b,c,d);
	PrintResult("Result 1:",a,b,c,d,result);
	a = 22;
	b = 55; 
	c = 98;
	d = 71;
	result = IntAddSubScalar(a,b,c,d);
	PrintResult("Result 2:",a,b,c,d,result);
	}
