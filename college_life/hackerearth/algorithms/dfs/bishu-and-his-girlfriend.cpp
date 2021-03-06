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

vector<string> split(string str,string sep){
	char* cstr=const_cast<char*>(str.c_str());
	char* current;
	vector<string> arr;
	current=strtok(cstr,sep.c_str());
	while(current!=NULL){
		arr.push_back(current);
		current=strtok(NULL,sep.c_str());
	}
	return arr;
}

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

const lli MAXN = 1e3+5;
vlli graph[MAXN];
lli girls[MAXN],visited[MAXN],dist[MAXN]= {0};

inline void dfs(lli start=1){
	visited[start] = 1;
	for(auto v:graph[start]){
		if(visited[v] != 1){
			dist[v] = dist[start]+1;
			visited[v] = 1;
			dfs(v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	fill(girls,girls+MAXN,0);
	fill(visited,visited+MAXN,0);
	n = t;
	rep(i,t-1){
		cin>>x>>y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	cin>>t;
	while(t--){
		cin>>x;
		girls[x] = 1;
	}
	dist[1] = 0;
	dfs();
	x = INT_MAX;y = -1;
	for (lli i = 1; i <= n; ++i){
		if(girls[i] == 1){
			if(dist[i] < x ){
				x = dist[i];
				y = i;
			}
			else if(dist[i] == x){
				y = min(y,i);
			}
		}
	}
	cout<<y<<endl;
	bye;
}

