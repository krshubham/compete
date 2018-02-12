#pragma comment (linker, "/stack:20000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828
#define stp(a,b) a.push(b)
#define all(a) a.begin(),a.end()
#define PI 3.1415926535897932384626433832795
#define rep(i,n) for( int i = 0; i < n; i++ )
#define endl '\n'

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef unsigned long long ull;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef unordered_map<lli,lli> umlli;
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

inline lli solve(vlli arr, lli n){
	lli dp[n+2];
	fill(dp,dp+(n+2),0);
	dp[0] = arr[0];
	lli c = dp[0];
	for (int i = 1; i < n; ++i){
		dp[i] = max(dp[i-1]+arr[i], max(arr[i],0LL));
		c = max(dp[i],c);
	}
	return c;
}

const lli MAXN = 5e5;

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,k,z,w;
	cin>>t;
	while(t--){
		cin>>n>>k;
		vlli v;
		x = INT_MIN;
		rep(i,n){
			cin>>d;
			v.pb(d);
			x = max(x,v[i]);
		}
		if(x <= 0){
			cout<<x<<endl;
		}
		else{
			x = solve(v,n);
			if (k == 1){
				cout<<x<<endl;
				continue;
			}
			for (int i = 0; i < n; ++i){
				v.pb(v[i]);
			}
			y = solve(v,2LL*n);
			for (int i = 0; i < n; ++i){
				v.pb(v[i]);
			}
			z = solve(v,3LL*n);
			for (int i = 0; i < n; ++i){
				v.pb(v[i]);
			}
			w = solve(v,4LL*n);
			if (x == y){
				cout<<x<<endl;
				continue;
			}
			else{
				lli tt = z-y;
				cout<<y+(k-2)*tt<<endl;
				continue;
			}
		}
	}
	bye;
}

