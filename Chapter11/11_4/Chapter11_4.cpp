#include<iostream>
using namespace std;

extern "C" int ldrInstrTest1_(unsigned int i,unsigned long j);
extern "C" long ldrInstrTest2_(unsigned int i,unsigned long j);
extern "C" short ldrInstrTest3_(unsigned int i,unsigned long j);

void ldrInstrTest1()
{
 unsigned int i = 5;
 unsigned long j = 8;
 int result1 = ldrInstrTest1_(i,j);
 cout<<"ldrInstrTest1() "<<result1 <<endl;
}
void ldrInstrTest2()
{
 unsigned int i = 1;
 unsigned long j = 3;
 long result2 = ldrInstrTest2_(i,j);
 cout<<"ldrInstrTest2() "<<result2 <<endl;
}
void ldrInstrTest3()
{
 unsigned int i = 0;
 unsigned long j = 4;
 short result3 = ldrInstrTest3_(i,j);
 cout<<"ldrInstrTest3() "<<result3 <<endl;
}

int main(int argc,char** argv){
 ldrInstrTest1();
 ldrInstrTest2();
 ldrInstrTest3();
 return 0;
}
