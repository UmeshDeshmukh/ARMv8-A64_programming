#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

extern "C" void meanStdev_(double* mean,
                     double* stdev,
					 const double* x,
					 int n);

void meanStdev(double* mean,
                double* stdev,
				const double* x,
				int n)
{
	double sum1 = 0.0;
	double sum2 = 0.0;
	
	for(int i=0;i<n;i++){
		sum1 += x[i]; 
	}
	*mean = sum1/n;
	for(int i=0;i<n;i++){
	    double temp = x[i]-(*mean);
		sum2 += temp*temp;
	}
    *stdev = sqrt(sum2/(n-1));	
}				
					 
int main()
{
	const char nl ='\n';
	double x[]={1,2,3,4,55,64,35,3,9,43};
	const int n = sizeof(x) / sizeof(double);
	double mean1=0.0,stdev1=0.0;
	double mean2=0.0,stdev2=0.0;
	
	meanStdev(&mean1,&stdev1,x,n);
	meanStdev_(&mean2,&stdev2,x,n);
	
	cout<<fixed<<setprecision(6);
	cout<<"Result of C++ function:"<<nl;
	cout<<"mean = "<<mean1<<"  std dev = "<<stdev1<<nl;
	cout<<"Result of Asm function:"<<nl;
	cout<<"mean = "<<mean2<<"  std dev = "<<stdev2<<nl;
}
