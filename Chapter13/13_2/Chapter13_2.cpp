#include<iostream>
#include<iomanip>

using namespace std;

extern "C" void sphereAreaVol_(double rad,double* sa,double* vol);

int main(int argc,char** argv)
{   const int w = 5;
    double surfArea,volume;
	double rad_vals[]{0.000001,0.2,1.0,3.333,6.667,7.57,9.998};
	size_t n_rad = sizeof(rad_vals)/sizeof(double);
	for(size_t i=0;i< n_rad;i++){
		sphereAreaVol_(rad_vals[i],&surfArea,&volume);
		cout<<"Radius:"<<rad_vals[i]<<"  ";
		cout<<"Surface Area:"<<setw(w)<<surfArea<<"  ";
		cout<<"Volume:"<<setw(w)<<volume<<'\n';
	}
	return 0;
}
