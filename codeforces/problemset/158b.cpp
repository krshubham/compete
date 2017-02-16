#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef double dbl;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	lli n,sum=0;
	cin>>n;
	for (int i = 0; i < n; ++i){
		lli a;
		cin>>a;
		sum+=a;
	}
	double z = (double)sum/4;
	cout<<ceil(z)<<endl;
	return 0;
}
