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
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828

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

int val[1005];


vector<int> graph[1005];


bool cmp(int u,int v){
	if(val[u]!=val[v])
		return val[u]>val[v];
	return u>v;
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,m,k,x,y;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	while(m--){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(graph[i].size()< k){
			cout<<"-1"<<endl;
			continue;
		}
		sort(graph[i].begin(),graph[i].end(),cmp);
		cout<<graph[i][k-1]<<endl;

	}
	bye;
}

