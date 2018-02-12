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

const lli MAXN = 3e5+5;

vlli graph[MAXN];
lli visited[MAXN];
lli dp[MAXN][26];

lli n,m,x,y,ans=0;
string s;


inline void dfs(lli u){
	visited[u] = 1;
	for(int i=0;i<graph[u].size();i++){
		int v = graph[u][i];
		if(!visited[v])
			dfs(v);
		if(visited[v] == 1){
			//cycle found
			cout<<-1<<endl;
			exit(0);
		}
		for(int j=0;j<26;j++){
			dp[u][j] = max(dp[u][j],dp[v][j]);
		}
	}
	dp[u][s[u-1]-'a']++;
	for(int i=0; i < 26; i++){
		ans = max(ans,dp[u][i]);
	}
	visited[u] = INT_MAX;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,a,b,c,d,e,f;
	cin>>n>>m;
	cin>>s;
	fill(visited,visited+MAXN,0);	
	rep(i,m){
		cin>>x>>y;
		graph[x].pb(y);
	}
	for (int i = 1; i <= n; ++i){
		if(visited[i] != 1){
			dfs(i);
		}
	}
	cout<<ans<<endl;
	bye;
}

