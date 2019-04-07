// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <cmath>
// #include <utility>
// #include <list>
// #include <iomanip>
// #include <stack>
// #include <climits>
// #include <queue>
// #include <string>
// #include <cstring>
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

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
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

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}

vector<int> graph[100005];
int color[100005];
bool vis[100005];

int val;

void dfs(int source, int prevColor) {
	vis[source]=true;
	if(color[source] != prevColor)
		val=0;
	for(int i=0;i<graph[source].size();i++) {
		if(vis[graph[source][i]]==false)
			dfs(graph[source][i], prevColor);
	}
	return;
}

bool solve(int node) {

	bool ans=true;
	val=1;
	memset(vis, false, sizeof(vis));
	vis[node]=true;
	for(int i=0; i<graph[node].size(); i++) {
		dfs(graph[node][i], color[graph[node][i]]);
		if(val==0) {
			ans=false;
			break;
		}
	}

	return ans;
}

int main() {
	int n,u,v;
	cin>>n;
	for(int i=0;i<n-1;i++) {
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	for(int i=1;i<=n;i++){
		cin>>color[i];
	}

	int x=0,y=0;

	for(int i=1;i<=n;i++) {
		for(int j=0;j<graph[i].size();i++) {
			if(color[i] != color[graph[i][j]]) {
				x=i;
				y=graph[i][j];
				break;
			}
		}
		if( (x!=0)&&(y!=0) )
			break;
	}

	if(x== 0 && y==0) {
		//root
		cout<<"YES"<<endl<<1<<endl;
		bye;
	}

	if(solve(x)) {
		cout<<"YES"<<endl;
		cout<<x<<endl;

	} 
	else if(solve(y)) {
		cout<<"YES"<<endl<<y<<endl;

	} else {
		cout<<"NO"<<endl;
	}

	return 0;
}