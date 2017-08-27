#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <iomanip>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

inline bool isPrime(lli n){
	if (n <= 1)  {
		return false;
	}
	if (n <= 3)  {
		return true;
	}

	if (n%2 == 0 || n%3 == 0) {
		return false;
	}
	
	for (int i=5; i*i<=n; i=i+6){
		if (n%i == 0 || n%(i+2) == 0){
			return false;
		}
	}

	return true;
}

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	lli m[n+1],v[n+1],g[n+1];
	fill(m,m+n,0);
	for (int i = 1; i < n; ++i){
		cin>>v[i];
	}
	cin>>t;
	while(t--){
		cin>>a>>b;
		for (int i = a; i <= b; ++i){
			m[i]++;
			g[i] = m[i] + m[n-i+1];
		}
	}
	for (int i = 1; i <= n; ++i){
		cout<<m[i]<<endl;
	}
	// if(!isEven(it->second)){
		// 	if(((it->first)-1) == (n-(it->first))){
		// 		continue;
		// 	}
		// 	d = v[(it->first)-1];
		// 	v[(it->first) - 1] = v[n - (it->first)];
		// 	v[n - (it->first)] = d;
		// }

	for (int i = 0; i < n; ++i){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	bye;
}

