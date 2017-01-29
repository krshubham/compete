#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a=1,b=1;
		ll c = -2*n;
		double coeff = b*b - 4*a*c;
		double d = pow(coeff,0.5);
		cout<<(ll)((d - b)/2*a)<<endl;
	}
	return 0;
}
