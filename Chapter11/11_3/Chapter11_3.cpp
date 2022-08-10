#include <iostream>
#include <cstdint>

using namespace std;

extern "C" void CalQuoRemA_(int a,int b,int* Q,int* R); 
extern "C" void CalQuoRemB_(long a,long b,long* Q,long* R);

int main(int argc,char** argv){
 int iA = -5,iB = 3,iQ,iR;
 long lA =500000000,lB =-3000000 ,lQ,lR;
 CalQuoRemA_(iA,iB,&iQ,&iR);
 cout<<"Output(CalQuoRemA_):"<<endl;
 cout<<"a= "<<iA<<endl;
 cout<<"b= "<<iB<<endl;
 cout<<"Quotient= "<<iQ<<endl;
 cout<<"Remainder= "<<iR<<endl;
 CalQuoRemB_(lB,lA,&lQ,&lR);
 cout<<"Output(CalQuoRemB_):"<<endl;
 cout<<"a= "<<lB<<endl;
 cout<<"b= "<<lA<<endl;
 cout<<"Quotient= "<<lQ<<endl;
 cout<<"Remainder= "<<lR<<endl;
 cout<<endl;
 return 0;
}
