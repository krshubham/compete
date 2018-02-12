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

lli m1;
void dfs(vector<ll>*v1,lli *visited,lli i){
	vector<ll>::iterator it1;

	for (it1=v1[i].begin();it1!=v1[i].end();it1++){
		if (visited[*it1] == 0){
			visited[*it1] = 1;
			m1++;
			dfs(v1,visited,*it1);
		}
	}
}

int main(){
	lli n,x,y,z;
	cin>>n;
	vlli v1[2*n];
	lli a = INT_MIN;
	lli b = INT_MAX;
	for (int i=0;i<n;i++){
		cin>>x>>y;
		v1[x-1].pb(y-1);
		v1[y-1].pb(x-1);
	}
	lli visited[2*n];
	fill(visited,visited+2*n,0);
	for (int i=0;i<2*n;i++){
		m1 = 1;
		if (visited[i] == 0){
			visited[i] = 1;
			dfs(v1,visited,i);
			if (m1 != 1){
				a = max(a,m1);
				b = min(b,m1);	
			}
			
		}
	}
	cout<<b<<" "<<a<<endl;
}