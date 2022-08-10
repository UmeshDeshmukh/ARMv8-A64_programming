#include<iostream>
#include<iomanip>

using namespace std;
//extern "C" sumOfSqrs(int64_t n,int64_t* sum_a,int64_t* sum_b);
extern "C" float cvtFtoC_(float F);
extern "C" float cvtCtoF_(float C);

int main(int argc,char** argv)
{   
    const int w = 10;
    float F_vals[] = {425.06f,-40.0f,0.0f,77.35f,67.05f};
    size_t n_F = sizeof(F_vals)/sizeof(float);
    cout<<setprecision(6); 	
	for(size_t i=0;i<n_F;i++){
		float C = cvtFtoC_(F_vals[i]);
		cout<<"i:"<<i;
		cout<<"F:"<<setw(w)<<F_vals[i]<<" ";
		cout<<"C:"<<setw(w)<<C<<'\n';
	}
	float C_vals[] = {100.0f,-10.0f,37.5f,4.05f,0.0f};
    size_t n_C = sizeof(C_vals)/sizeof(float);
    cout<<setprecision(6); 	
	cout<<"Celsius to F"<<'\n';
	for(size_t i=0;i < n_C;i++){
		float F = cvtCtoF_(C_vals[i]);
		cout<<"i:"<<i;
		cout<<"C:"<<setw(w)<<C_vals[i]<<" ";
		cout<<"F:"<<setw(w)<<F<<'\n';
	}
	return 0;
}
