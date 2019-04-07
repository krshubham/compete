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
#define maxN 5005
#define base 1000000007

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

int f[maxN][maxN] = {0},s[maxN][maxN] = {0},i,j,k,m,n;
int main () {
	char c;
	cin >> n;
	f[1][0] = 1;
	for (i = 1; i <= n; i++) {
		s[i][0] = f[i][0];
		for (j = 1; j <= i; j++) {
			s[i][j] = s[i][j-1] + f[i][j]; 
		}
		cin >> c;
		if (c == 'f') {
			for (j = 0; j <= i; j++) {
				f[i+1][j+1] += f[i][j];
			}
		}
		else if (c == 's') {
			f[i+1][0] = s[i][i];
			for (j = 1; j <= i; j++) {
				f[i+1][j] = s[i][i] - s[i][j-1];
			}
		}
	}

	k = 0;
	for (i = 0; i <= n; i++) {
		k =  k + s[n][i];
	}
	cout << s[n][n] % base<<endl;
}
