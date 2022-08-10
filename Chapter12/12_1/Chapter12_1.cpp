#include<iostream>
#include<iomanip>
#include<cstdint>

using namespace std;

extern "C" int64_t sumOfCubes_( 
                               uint64_t a,
                               uint32_t b,
                                uint8_t c,
                               uint16_t d,
                                int16_t e,
                                 int8_t f,
                                int32_t g,
                                int64_t h,
                                int32_t i,
                               uint32_t j);
int64_t sumOfCubes(uint64_t a,
                   uint32_t b,
                    uint8_t c,
                   uint16_t d,
                    int16_t e,
                     int8_t f,
                    int32_t g,
                    int64_t h,
                    int32_t i,
                   uint32_t j)
{
	int64_t aa = (int64_t)a*a*a;
	int64_t bb = (int64_t)b*b*b;
	int64_t cc = (int64_t)c*c*c;
	int64_t dd = (int64_t)d*d*d;
	int64_t ee = (int64_t)e*e*e;
	int64_t ff = (int64_t)f*f*f;
	int64_t gg = (int64_t)g*g*g;
	int64_t hh =           h*h*h;
	int64_t ii = (int64_t)i*i*i;
	int64_t jj = (int64_t)j*j*j;
	
	return aa+	bb+	cc+	dd+	ee+	ff+	gg+	hh+	ii+	jj;
	
}							   

int main(int argc,char** argv)
{   
    uint64_t a = 899023456;
    uint32_t b = 8990123;
     uint8_t c = 80;
    uint16_t d = 9003;
     int16_t e = -1245;
      int8_t f = 207;
     int32_t g = -98000;
     int64_t h = -564323229764, sum1, sum2;
     int32_t i = 3456994;
    uint32_t j = 23478975;
	
	sum1 = sumOfCubes(a,b,c,d,e,f,g,h,i,j);
	sum2 = sumOfCubes_(a,b,c,d,e,f,g,h,i,j);
	
	cout<<"c++ result: "<<sum1<<endl;
	cout<<"Asm result: "<<sum2<<endl;
	
	return 0;
}

