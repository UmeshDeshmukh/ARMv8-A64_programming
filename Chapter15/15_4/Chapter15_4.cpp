#include<iostream>
#include<iomanip>
#include<string>
#include<random>
#include "AlignedMem.h"

using namespace std;

extern "C" bool corrCoeff_(float* rho,float sum[5],
const float*x,const float* y,size_t n,float eps);
const size_t memAlign = 16;
int w = 5;
int main()
{
	//initialize values
	AlignedArray<float> x_aa(120,memAlign);
	AlignedArray<float> y_aa(120,memAlign);
	float* x = x_aa.Data();
	float* y = y_aa.Data();
    uniform_real_distribution<float>u_dist{0.0,50.0};
    normal_distribution<float>n_dist{25.0,7.0};
	mt19937 rng{44};
	for(size_t i=0;i<120;i++){
		x[i] = round(u_dist(rng));
		y[i] = x[i] + round(n_dist(rng));
    }
	float rho, eps = 1.0e-9,sum[5];
	bool flag = corrCoeff_(&rho,sum,x,y,120,eps);
	if(flag){
		cout << fixed << setprecision(2);
		cout << setprecision(2);
        cout << "sum_x: " <<  setw(w) << sum[0] << '\n';
        cout << "sum_y: " <<  setw(w) << sum[1] << '\n';
        cout << "sum_xx: " << setw(w) << sum[2] << '\n';
        cout << "sum_yy: " << setw(w) << sum[3] << '\n';
        cout << "sum_xy: " << setw(w) << sum[4] << '\n';
        cout << "rho: " << setw(w) << rho << '\n';
	}
	return 0;
}

