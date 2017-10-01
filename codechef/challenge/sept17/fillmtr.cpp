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



void dfs(vector<pair<int,int> >*v1,int *visited,int *traverse,int *key,int i,int &ans){
	vector<pair<int,int> >::iterator it1;
	if (traverse[i] == 0){
		visited[i] = 1;
		for (it1 = v1[i].begin();it1 != v1[i].end();it1++){
			if (visited[(*it1).first] == 0){

				key[(*it1).first] = (key[i])^((*it1).second);
				dfs(v1,visited,traverse,key,(*it1).first,ans); 
			}
			else{
				if (key[(*it1).first] != (key[i])^((*it1).second)){
					ans = 1;
					break;
				}
			}
			if (ans == 1)
				break;   
		}
		if (ans == 1)
			return;
		traverse[i] = 1;
	}

}


int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		int n,q,x,y,z,a=0,b,c,ans=0;
		cin>>n>>q;
		vector<pair<int,int> >v1[n];
		int visited[n];
		int traverse[n];
		int key[n];
		for(int i=0;i<n;i++)
			visited[i] = 0;
		for(int i=0;i<n;i++)
			traverse[i] = 0;
		for (int i=0;i<n;i++)
			key[i] = 0;
		for (int i=0;i<q;i++){
			cin>>x>>y>>z;
			if (x == y && z == 1){
				a = 1;
				continue;
			}
			else if (x != y){
				v1[x-1].pb(mp(y-1,z));
			}

		}
		if (a == 1){
			cout<<"no"<<endl;
			continue;
		}

		for (int i=0;i<n;i++){
			if (visited[i] == 0){
				key[i] = 0;
				dfs(v1,visited,traverse,key,i,ans);
				if (ans == 1)
					break;
			}
		}
		if (ans == 1){
			cout<<"no"<<endl;
		}
		else{
			cout<<"yes"<<endl;
		}
	}
	bye;
}