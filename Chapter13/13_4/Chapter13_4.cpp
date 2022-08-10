#include<iostream>
#include<iomanip>
#include<string>
#include<limits>

using namespace std;

extern "C" void comapareFloat_(float a,float b,bool* results);

int main(int argc,char** argv){
	const char* ops[]={"EQ","NE","GT","LT","GE","LE","U0"};
	size_t n_ops = sizeof(ops)/sizeof(float);
	bool results[7];
	
	float f_a[]{-77.45,100.45,0.00001,44546738903.23423,8.324,0.0};
	float f_b[]{777.45,100.05,0.000011,44546738903.23423,-88.324,69.0};
	f_a[5] = numeric_limits<float>::quiet_NaN();
	for(size_t i=0;i<6;i++){
		comapareFloat_(f_a[i],f_b[i],results);
		cout<<"a ="<<f_a[i]<<","<<"b ="<<f_b[i]<<'\n';
		for(size_t j=0;j<7;j++){
			cout<<ops[j]<<" = "<<boolalpha<<results[j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
