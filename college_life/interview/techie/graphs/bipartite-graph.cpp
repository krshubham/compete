// to determine if a given graph is bipartite or not
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

//if a graph is 2 colorable then it is a bipartite graph
lli color[100005],visited[100005];

bool bfs(vlli graph[],lli source=1){
	queue<lli> Q;
	Q.push(source);
	visited[source] = 1;
	while(!Q.empty()){
		lli parent = Q.front();
		Q.pop();
		color[parent] = 1;
		for(lli vertex:graph[parent]){
			visited[vertex] = 1;
			if(color[vertex] == -1){
				color[vertex] = 1-color[parent];
			}
			else if(color[vertex] == color[parent]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,m;
	cin>>n>>m; //no of vertices and edges
	vlli graph[n+2];
	fill(color,color+100005,-1);
	fill(visited,visited+100005,0);
	rep(i,m){
		cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	for (lli i = 1; i <= n; ++i){
		if(visited[i] == 0){
			if(!bfs(graph,i)){
				cout<<"Not bipartite"<<endl;
				bye;
			}
		}
	}
	cout<<"The graph is bipartite"<<endl;
	bye;
}

