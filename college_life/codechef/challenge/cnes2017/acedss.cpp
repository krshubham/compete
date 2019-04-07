#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <iomanip>
#include <stack>
#include <climits>
#include <queue>
#include <string>
#include <cstring>
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

void bfs(vlli graph[], lli start, lli n){
	mlli visited;
	visited[start] = 1;
	queue<lli> Q;
	Q.push(start);
	while(!Q.empty()){
		lli x = Q.front();
		Q.pop();
		for(lli node: graph[x]){
			if(visited[node] != 1){
				Q.push(node);
				visited[node] = 1;
			}
		}
	}
	lli c = 0;
	for (int i = 0; i < n; ++i){
		if(visited[i] != 1) c++;
	}
	cout<<c+1<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>b;
		if(b == 0){
			cout<<n<<endl;
			continue;
		}
		vlli graph[n+1];
		rep(i,b){
			cin>>x>>y;
			graph[x].pb(y);
			graph[y].pb(x);
		}
		bfs(graph,0,n);
	}
	bye;
}

