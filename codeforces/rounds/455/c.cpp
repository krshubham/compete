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
#define modulo (ll) (1e9 + 7)
#define max_size 5007

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
 
ll n;
char s[max_size];
ll dp[max_size][max_size];
 
ll sol(ll i, ll pos) {
	if (i == n) { return 1; }
	if (dp[i][pos] != 0) { return dp[i][pos]; }
 
	ll ans = 0;
 
	if (s[i] == 'f') {
		ans = (ans%modulo + sol(i + 1, pos + 1)%modulo)%modulo;
	} else {
		for (ll k=1; k <= pos; k++) {
			ans = (ans%modulo + sol(i + 1, k)%modulo)%modulo;
		}
	}
 
	dp[i][pos] = ans;
	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (ll i=1; i <= n; i++) {
		cin >> s[i];
	}
	cout << sol(1, 1) << endl;
	return 0;
}