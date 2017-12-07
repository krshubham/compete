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
typedef pair<int, int>pl;
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

const int V = 1000010;
char get() {
	static char buf[V], *p1 = buf, *p2 = buf;
	if (p1 == p2) {
		p2 = (p1 = buf) + fread(buf, 1, V, stdin);
		if (p1 == p2) return EOF;
	}
	return *p1++;
}


void Read(int &x) {
	x = 0;
	static char c;
	while (c > '9' || c < '0') c = get();
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = get();
	}
}


int N, M, T, a[V], b[V];
int v[V], pos[V], tot;
int vis[100], p[100], pp[100], mx;
vlli G[V];
pl a1[V], a2[V][2];
void dfs(int x) {
	if (x == tot + 1) {
		int now = 0;
		for (int i = 1; i <= tot; i++)
			if (v[i] != v[p[i]]) now++;
		if (now >= mx) {
			mx = now;
			for (int i = 1; i <= tot; i++) pp[i] = p[i];
		}
	return ;
}
for (int i = 1; i <= tot; i++)
	if (!vis[i]) {
		vis[i] = 1;
		p[x] = i;
		dfs(x + 1);
		vis[i] = 0;
	}
}
void solve() {
	int i, j;
	for (i = 1; i <= M; i++) G[i].clear();
		mx = M = tot = 0;

	Read(N);
	for (i = 1; i <= N; i++) {
		Read(a[i]);
		G[a[i]].push_back(i);
		M = max(M, a[i]);
	}
	int n1 = 0, n2 = 0;
	for (i = 1; i <= M; i++) {
		if (G[i].size() == 1) {
			n1++;
			a1[n1] = pl(i, G[i][0]);
		}
		if (G[i].size() == 2) {
			n2++;
			a2[n2][0] = pl(i, G[i][0]);
			a2[n2][1] = pl(i, G[i][1]);
		}
	}
	int p1 = min(3, n1), p2 = min(2, n2);
	if (n1 - p1 == 1) p1--;
	if (n2 - p2 == 1) p2++;
	for (i = 1, j = n1; i <= p1; i++, j--) {
		++tot, v[tot] = a1[j].first, pos[tot] = a1[j].second;		
	}
	for (i = 1, j = n2; i <= p2; i++, j--) {
		++tot, v[tot] = a2[j][0].first, pos[tot] = a2[j][0].second;
		++tot, v[tot] = a2[j][1].first, pos[tot] = a2[j][1].second;
	}
	n1 -= p1;
	n2 -= p2;
	for (i = 1; i <= n1; i++) {
		j = (i + 1);
		if (i == n1) j = 1;
		b[a1[j].second] = a1[i].first;
	}
	for (i = 1; i <= n2; i++) {
		j = (i + 1);
		if (i == n2) j = 1;
		b[a2[j][0].second] = a2[i][0].first;
		b[a2[j][1].second] = a2[i][1].first;
	}
	dfs(1);
	for (i = 1; i <= tot; i++) b[pos[i]] = v[pp[i]];
		if (N == 1) printf("0\n");
	else printf("%d\n", n1 + n2 * 2 + mx);
	for (i = 1; i <= N; i++) {
		printf("%d%c", b[i], i == N ? '\n' : ' ');
	}
}
int main() {
	int i, j;
	Read(T);
	while (T--) {
		solve();
	}
	return 0;
}