#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef double dbl;

int main(int argc, char const *argv[]){
	lli t;
	cin>>t;
	while(t--){
		lli n,a;
		cin>>n;
		ulli xfsum = 0,xsecsum = 0,yfsum = 0, ysecsum = 0;
		for (int i = 1; i <= n; ++i){
			cin>>a;
			if(i%2 != 0){
				xfsum += a;
			}
			else{
				xsecsum += a;
			}
		}
		for (int i = 1; i <= n; ++i){
			cin>>a;
			if(i%2 != 0){
				yfsum += a;
			}
			else{
				ysecsum += a;
			}
		}
		((xfsum + ysecsum) <= (xsecsum + yfsum)) ? cout<<xfsum + ysecsum<<endl : cout<<xsecsum + yfsum<<endl;
	}	
	return 0;
}
