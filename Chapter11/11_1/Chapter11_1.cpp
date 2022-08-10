#include<iostream>

using namespace std;

extern "C" int IntAddSubScalar_(int a,int b,int c,int d);
void PrintResult(const char* str,int a,int b,int c,int d,int result);

void PrintResult(const char* str,int a,int b,int c,int d,int result){
	cout<<str<<endl;
	cout<<"a = "<< a <<endl;
	cout<<"b = "<< b <<endl;
	cout<<"c = "<< c <<endl;
	cout<<"d = "<< d <<endl;
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
