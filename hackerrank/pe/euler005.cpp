#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

unsigned long long findlcm(unsigned long long a, unsigned long long b){
	return (a*b)/__gcd(a, b);
}

// Driver Code
int main(){
	ll n,x,t;
	cin>>t;
	unsigned long long res[42];
	res[0] = 1;
	for (unsigned long long i = 1; i <= 40; ++i){
		res[i] = findlcm(res[i-1],i);
	}
	while(t--){
		cin>>n;
		cout<<res[n]<<endl;
	}
	return 0;
}