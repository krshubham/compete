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

lli visited[100005];
lli level[100005];
inline int bfs(lli n,vplli graph[],lli source=1){
	queue<lli> Q;
	visited[source] = 1;
	level[source] = 0;
	Q.push(source);
	while(!Q.empty()){
		lli parent = Q.front();
		Q.pop();
		for(auto child: graph[parent]){
			if(visited[child.first] != 1){
				visited[child.first] = 1;
				Q.push(child.first);
				level[child.first] = level[parent] + child.second;
			}
		}
	}
	lli c = 0;
	lli d = 0;
	rep(i,n+2){
		if(level[i] > c){
			c = level[i];
			d = i;
		}
	}
	return d;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		cin>>n;
		vplli graph[n+2];
		fill(visited,visited+100005,0);
		fill(level,level+100005,-1);
		rep(i,n-1){
			cin>>x>>y>>a;
			graph[x].pb(mp(y,a));
			graph[y].pb(mp(x,a));
		}
		x = bfs(n,graph);
		fill(visited,visited+100005,0);
		fill(level,level+100005,-1);
		y = bfs(n,graph,x);
		x = level[y];
		if(x < 100){
			cout<<0<<" ";
		}
		else if(x > 100 && x <= 1000){
			cout<<100<<" ";
		}
		else if(x > 1000 && x<= 10000){
			cout<<1000<<" ";
		}
		else{
			cout<<10000<<" ";
		}
		cout<<x<<endl;
	}
	bye;
}

