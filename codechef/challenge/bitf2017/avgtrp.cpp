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

#define F first
#define S second
const int mod = 1e9+7;
inline int add(int a, int b){a += b; if(a >= mod) a -= mod; return a;}
inline int sub(int a, int b){a -= b; if(a < 0) a += mod; return a;}
const int N = 200005;
int x[N], P[N];
int ft[2][N];
set<int> s;
map<int,int> myp;
vector<pair<int,int> > vec;

int sum(int k, int b){
	int ret = 0;
	for (; b; b -= (b & (-b))) ret = add(ret, ft[k][b]);
		return ret;	
}
int sum(int k, int l, int r){
	return sub(sum(k,r), sum(k, l - 1));
}
void update(int i, int k, int v){
	for (; k < N; k += (k & (-k))) ft[i][k] = add(ft[i][k], v);
}

int main(){
	int t, n, m;
	cin >> t;
	while(t--){
		cin >> n; m = 0; memset(ft, 0, sizeof ft);
		s.clear(), myp.clear(); vec.clear();
		for(int i = 1; i <= n; i++) cin >> x[i], s.insert(x[i]);
			for(int i = 1; i <= n; i++) cin >> P[i], vec.push_back(mp(P[i], x[i]));
				for(int ele: s)myp[ele] = ++m;
					sort(vec.begin(), vec.end());
				int ans = 0;
				for(int i = 0;i < n;i++){
					int ind = myp[vec[i].S];
					ll suml = sum(0, ind), cntl = sum(1, ind);
					ll sumr = sum(0, ind, m), cntr = sum(1, ind, m);
					ans += (vec[i].F * ((cntl - cntr) * vec[i].S + sumr - suml))%mod;
					ans %= mod;
					update(0, ind, vec[i].S);
					update(1, ind, 1);
				}
				cout << (ans%mod + mod)%mod << endl;
			}
		}