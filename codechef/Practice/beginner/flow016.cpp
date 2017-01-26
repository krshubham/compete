#include <iostream>
using namespace std;

typedef long long ll;

ll gcd_recursive(ll a, ll b){
    if (b)
        return gcd_recursive(b, a % b);
    else
        return a;
}

int main(int argc, char const *argv[]){
	ll a;
	cin>>a;
	while(a--){
		ll b,c;
		scanf("%lld %lld",&b,&c);
		ll gcd = gcd_recursive(b,c);
		ll lcm = (b*c)/gcd;
		cout<<gcd<<" "<<lcm<<endl;
	}

	return 0;
}