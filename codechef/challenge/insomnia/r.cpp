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
#include <stack>
#include <climits>
#include <queue>
#include <bitset>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828
#define stp(a,b) a.push(b)
#define all(a) a.begin(),a.end()
#define PI 3.1415926535897932384626433832795

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

ulli countSetBits(ulli n){
	ulli count = 0;
	while (n){
		n = n & (n-1) ;
		count++;
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(0);
	ulli t,n,a,b,c,d,e,f,x,y;
	// cin>>t;
	t = 1;
	while(t--){
		// cin>>n;
		n = 1000000000;
		c = 0;
		for (int i = 1; i <= n; ++i){
			c = mod(mod(c) + mod(i*(bitset<32>(i).count())));
			// cout<<"i = "<<i<<" and set bits = "<<__builtin_popcountll(i)<<endl;
		}
		cout<<mod(c)<<endl;
	}
	bye;
}

