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
#define endl '\n'
#define first F
#define second S

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


// void dfs(vlli graph[], lli start){
// 	visited[start] = 1;
// 	for (lli x:graph[start]){
// 		if(visited[x] != 1){
// 			dfs(graph,x);
// 			visited[x] = 1;
// 		}
// 	}
// }

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	mlli visited;	
	lli graph[n+1];
	rep(i,n){
		cin>>x;
		graph[i+1] = x;
	}
	c = 0;
	// for (int i = 0; i < n; ++i){
	// 	if(visited[i+1] != 1){
	// 		dfs(graph,i+1);
	// 		c++;
	// 	}
	// }
	vlli v;
	d = 0;
	for (int i = 1; i <= n; ++i){
		if(visited[i] == 0) {
			x = i;
			c = 0;
			do{
				++c;
				visited[x] = 1;
				x = graph[x];
			}
			while(x != i);
			v.pb(c);
			d += c*c;
		}
	}
	if(v.size() > 1){
		sort(all(v));
		d += 2*v[v.size() - 1] * v[v.size() - 2];
	}
	cout<<d<<endl;
	bye;
}

