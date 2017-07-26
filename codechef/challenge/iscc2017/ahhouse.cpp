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

typedef struct vertex{
	vector<vertex> neighbours;
	lli pf;
	lli pt;
	bool visited; 
} vertex;


int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vlli graph[n][m];
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j){
				if(i+1 <= n*m){
					graph[i][j].pb(i+1);
				}
				if(i-1>= 1){
					graph[i][j].pb(i-1);
				}
				if(j+1 <= m){
					graph[i][j].pb(j+1);
				}
				if(j-1 >= 1){
					graph[i][j].pb(j-1);
				}
			}
		}
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j){
				cout<<"row "<<i<<" column "<<j<<endl;
				vlli::iterator iter = graph[i][j].begin();
				for (; iter != graph[i][j].end(); ++iter){
					cout<<*iter<<" ";
				}
			}
		}
	}
	bye;
}

