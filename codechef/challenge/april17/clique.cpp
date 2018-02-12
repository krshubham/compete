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

vplli graph[(int)1e5+10];
lli dist[(int)1e5+10];
void dijkstra(int s){
	priority_queue<plli, vplli, greater<plli> > Q;
	while(!Q.empty())
		Q.pop();

	Q.push(make_pair(0, s));
	dist[s] = 0;
	while (!Q.empty()) {
		plli p = Q.top();
		Q.pop();

		int here = p.second;
		if (dist[here] != p.first) continue;

		for (vplli::iterator it = graph[here].begin(); it != graph[here].end(); it++) {
			if (dist[here] + it->first < dist[it->second]) {
				dist[it->second] = dist[here] + it->first;
				Q.push(make_pair(dist[it->second], it->second));
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,k,m,s;
	cin>>t;
	while(t--){
		cin>>n>>k>>x>>m>>s;
		for (int i = 1; i <= n; ++i){
			dist[i] = INT_MAX;
			graph[i].clear();
		}
		for (int i = 1; i <= m; ++i){
			cin>>a>>b>>c;
			graph[a].pb(mp(c,b));
			graph[b].pb(mp(c,a));
		}
		if(s <= k){
			for (int i = 1; i <= k; ++i){
				if(i == s) continue;
				if(graph[i].size() > 0){
					graph[i].pb(mp(x,s));
					graph[s].pb(mp(x,i));
				}
			}
			dijkstra(s);
			for(int i = 1; i <= k; i++){
				dist[i]=min(x,dist[i]);
			}
		}
		else{
			dijkstra(s);
			lli minv = 0LL;
			lli mind = INT_MAX;
			for (int i = 1; i <= k; ++i){
				if(dist[i] < mind){
					mind = dist[i];
					minv = i;
				}
			}
			for (int i = 1; i <= k; ++i){
				if(i == minv) continue;
				if(graph[i].size() > 0){
					graph[i].pb(mp(x,minv));
					graph[minv].pb(x,i);
				}
			}
		}
		for (int i = 1; i < count; ++i){
			/* code */
		}
	}
	bye;
}