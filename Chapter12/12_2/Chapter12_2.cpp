#include<iostream>
#include<cstdint>

using namespace std;

int64_t global_var1;
int32_t global_var2;

extern "C" void local_Var_(int32_t a,
                           int32_t b,
                           int32_t c,
						   int32_t d,
						   int64_t e,
                           int64_t f,
                           int64_t g,
                           int64_t h,
                           int32_t*x, 
                           int64_t*y );
						   
void local_Var(int32_t a,
               int32_t b,
               int32_t c,
	       int32_t d,
	       int64_t e,
               int64_t f,
               int64_t g,
               int64_t h,
               int32_t*x, 
               int64_t*y )
{
	int32_t t0 = a+b-c;
	int32_t t1 = d+global_var2;
        int64_t t2 = e-f+g;
        int64_t t3 = h-global_var1;
        *x = t0*t1;
        *y = t2*t3;	
			   }			   



int main(int argc,char** argv)
{
	int32_t a = 4462;
	int32_t b = 7584;
	int32_t c = -1299;
	int32_t d = 9746;
	int64_t e = 9827463;
	int64_t f = -2574367;
	int64_t g = -7346437;
	int64_t h = 4857489;
	int32_t x; 
        int64_t y;
	local_Var(a,b,c,d,e,f,g,h,&x,&y);
	cout<<"C++ result: "<<endl;
        cout <<x<<" "<<y<<endl;
	local_Var_(a,b,c,d,e,f,g,h,&x,&y);	    
        cout<<"Asm result: "<<x<<" "<<y<<endl; 	
	return 0;
}
