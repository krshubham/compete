#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ll a;
	cin>>a;
	while(a--){
		int b,c,lcm;
		cin>>b>>c;
		int gcd = __gcd(b,c);
		lcm = (b*c)/__gcd(b,c);
		cout<<gcd<<" "<<lcm<<endl;
	}

	return 0;
}