#include<iostream>
#include<cstdint>

using namespace std;
extern "C" bool compareA_(int32_t a,int32_t b,int32_t c,int32_t* sum);
extern "C" bool compareC_(int32_t a,int32_t b,int32_t c,int32_t* sum);
extern "C" bool compareB_(int64_t a,int64_t b,int64_t c,int64_t* sum);

template<typename T>
void printResult(const char*msg,T a,T b,T c,T sum,bool result)
{
	const char nl = '\n';
	const char* sep = " | ";
	cout<<msg<<nl;
	cout<<"a= "<<a<<sep;
	cout<<"b= "<<b<<sep;
	cout<<"c= "<<c<<sep;
	cout<<"sum= "<<sum<<sep;
    cout<<"result= "<<boolalpha<<result<<nl;
	cout<<nl;
}

int main(int argc,char** argv)
{
	int32_t a1,b1,c1,sum1;
	int64_t a2,b2,c2,sum2;
	bool result;
	
	a1 = 10,b1 = 20,c1 = 30;
	result = compareA_(a1,b1,c1,&sum1);
	printResult("compareA_ Test#1",a1,b1,c1,sum1,result);
	a1 = 60,b1 = 25,c1 = 35;
	result = compareA_(a1,b1,c1,&sum1);
	printResult("compareA_ Test#2",a1,b1,c1,sum1,result);
	
	a2 = 6456743099,b2 = 2235785,c2 = 39865435;
	result = compareB_(a2,b2,c2,&sum2);
	printResult("compareB_ Test#1",a2,b2,c2,sum2,result);
	a2 = -6456743021,b2 = 2235785,c2 = 39865435;
	result = compareB_(a2,b2,c2,&sum2);
	printResult("compareB_ Test#1",a2,b2,c2,sum2,result);
	
	a1 = 10,b1 = 20,c1 = 30;
	result = compareC_(a1,b1,c1,&sum1);
	printResult("compareC_ Test#1",a1,b1,c1,sum1,result);
	a1 = 1073741823,b1 = 1073741800,c1 = 0;
	result = compareC_(a1,b1,c1,&sum1);
	printResult("compareC_ Test#2",a1,b1,c1,sum1,result);
	a1 = 1073741823,b1 = 5,c1 = 1073741823;
	result = compareC_(a1,b1,c1,&sum1);
	printResult("compareC_ Test#3",a1,b1,c1,sum1,result);
	return 0;
}
