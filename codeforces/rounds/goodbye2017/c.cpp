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

int main(){
	ios_base::sync_with_stdio(0);
	lli n,r;
	cin>>n>>r;
	lli t[n];
	for(lli i=0;i<n;i++) {
		cin>>t[i];
	}
	long double ans[n];
	ans[0] = r;
	for(lli i=1;i<n;i++){
		long double x = 0;
		for(lli j=0;j<i;j++){
			if(abs(t[i]-t[j]) <= 2*r){
				long double y = sqrt(4*r*r - (t[i]-t[j]) * (t[i]-t[j]));
				x = max(x,ans[j] + y);
			}
		}
		ans[i] = max(x,(long double)r);
	}
	for(lli i=0;i<n;i++){
		cout<<setprecision(20)<<fixed<<ans[i]<<" ";
	}
	cout<<endl;
	bye;
}
