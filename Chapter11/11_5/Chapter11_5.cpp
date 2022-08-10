#include<iostream>
#include<cstdint>
using namespace std;

extern "C" void MoveA_(int32_t& a0, int32_t& a1, int32_t& a2, int32_t& a3);
extern "C" void MoveB_(int64_t& b0, int64_t& b1, int64_t& b2, int64_t& b3);
extern "C" void MoveC_(int32_t& c0, int32_t& c1);
extern "C" void MoveD_(int64_t& d0, int64_t& d1, int64_t& d2);

int main(int argc,char** argv)
{
	int32_t a0,a1,a2,a3,c0,c1;
	int64_t b0,b1,b2,b3,d0,d1,d2;
	
	MoveA_(int32_t& a0, int32_t& a1, int32_t& a2, int32_t& a3);
	cout<<"a0= "<<a0<<" a1= "<<a1<<" a2= "<<a2<<" a3= "<<a3<<endl; cout<<endl;
	
	MoveB_(int64_t& b0, int64_t& b1, int64_t& b2, int64_t& b3);
	cout<<"b0= "<<b0<<" b1= "<<b1<<" b2= "<<b2<<" b3= "<<b3<<endl; cout<<endl;
	
	MoveC_(int32_t& c0, int32_t& c1);
	cout<<"c0= "<<c0<<" c1= "<<c1<<endl; cout<<endl;
	
	MoveD_(int64_t& d0, int64_t& d1, int64_t& d2);
	cout<<"d0= "<<d0<<" d1= "<<d1<<" d2= "<<d2<<endl; cout<<endl;
	return 0;
}
