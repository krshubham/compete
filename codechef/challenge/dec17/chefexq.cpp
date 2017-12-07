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
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )
#define endl '\n'
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef unsigned long long ull;
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

const int V = 110010;

int ch[V * 220][2], Val[V * 220], tot, Rt[V];
void insert(int x, int v, int y) {
	int now = Rt[x], i, j;
	for (i = 20; ~i; i--) {
		j = v & 1;
		if (!ch[now][j]) ch[now][j] = ++tot;
		now = ch[now][j];
		v >>= 1;
	}
	Val[now] += y;
}

int query(int x, int v) {
	int now = Rt[x], i, j;
	for (i = 20; ~i; i--) {
		j = v & 1;
		if (!ch[now][j]) return 0;
		now = ch[now][j];
		v >>= 1;
	}
	return Val[now];
}

int N, M, a[V], p[V], l[V], r[V], bel[V], B, Xor[V];

int main() {
	int i, j;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	B = (sqrt(N) / 4 + 1) * 3;
	for (i = 1; i <= N; i++) Rt[i] = i;
		tot = N + 1;
	for (i = 1; i <= N; i++){
		cin>>a[i];
	}
	for (i = 1; i <= N; i++) {
		p[i] = p[i - 1] ^ a[i];		
	}
	for (i = 1; i <= N; i++) {
		bel[i] = (i - 1) / B + 1;
		if (!l[bel[i]]) l[bel[i]] = i;
		r[bel[i]] = i;
	}
	B = bel[N];
	for (i = 1; i <= B; i++) {
		for (j = l[i]; j <= r[i]; j++){
			insert(i, p[j], 1);
		}
	}
	int op, x, y;
	while (M--) {
		cin>>op>>x>>y;
		if (op & 1) {
			y = y ^ a[x];
			a[x] ^= y;
			for (i = x; i <= r[bel[x]]; i++) {
				insert(bel[x], p[i], -1);
				p[i] ^= y;
				insert(bel[x], p[i], 1);
			}
			for (i = bel[x] + 1; i <= B; i++) {
				Xor[i] ^= y;
			}
		} 
		else {
			int Ans = 0;
			for (i = 1; i <= bel[x] - 1; i++)
				Ans += query(i, y ^ Xor[i]);
			for (i = l[bel[x]]; i <= x; i++)
				if ((p[i] ^ Xor[bel[x]]) == y) Ans++;
			cout<<Ans<<endl;
		}
	}
	return 0;
} 