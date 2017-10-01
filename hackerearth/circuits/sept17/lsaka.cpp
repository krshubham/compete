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

void treep(vlli tree[], lli n){
	for (int i = 1; i <= n; ++i){
		for(lli j:tree[i]){
			cout<<j<<" ";
		}
		cout<<endl;
	}
}

lli k;
mlli ans,sizes;
vlli cq[1000002];

void dfs(lli current, lli parent, vlli colors, vlli tree[]){
	lli x = colors[current];
	if(sizes[x]>=k)
		ans[current] = cq[x][sizes[x]-k];
	cq[x].pb(current);
	sizes[x] += 1;
	for(lli child: tree[current]){
		if(child != parent){
			dfs(child,current, colors, tree);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>a>>k;
	vlli colors(a+1);
	vlli tree[a+1];
	colors[0] = 0;
	for (int i = 1;i <=a; ++i){
		cin>>colors[i];
	}
	rep(i,a-1){
		cin>>x>>y;
		tree[x].pb(y);
		tree[y].pb(x);
	}
	dfs(1,0,colors,tree);
	for (int i = 0; i <= a; ++i){
		if(ans[i] != 0) cout<<ans[i]<<endl;
		else cout<<-1<<endl;
	}
	bye;
}

