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

char mat[55][55];
char seq[105];

pair <int,int> p[] = {{1,0},{0,1},{-1,0},{0,-1}};

bool ok(int idx,int x,int y){
	if(idx==strlen(seq))return false;
	int px = p[seq[idx]-'0'].first;
	int py = p[seq[idx]-'0'].second;
	x += px;
	y += py;
	if(mat[x][y]!='E' && mat[x][y]!='.' && mat[x][y]!='S') {
		return false;
	}
	if(mat[x][y]=='E')return true;
	return ok(idx+1,x,y);
}

int main() {
	int n,m;
	cin >> n >> m;
	int sx,sy;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> mat[i][j];
			if(mat[i][j]=='S'){
				sx=i,sy=j;
			}
		}
	}
	cin>>seq;
	sort(p,p+4);
	int r=0;
	do{
		r += ok(0,sx,sy);
	}while(next_permutation(p,p+4));
	cout << r<<endl;
	return 0;
}
