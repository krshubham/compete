#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	int t,a;
	double b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a>1000){
			b = 0.90*b;
			cout<<fixed<<setprecision(6)<<a*b<<endl;
		}
		else{
			cout<<fixed<<setprecision(6)<<a*b<<endl;
		}
	}
	return 0;
}
