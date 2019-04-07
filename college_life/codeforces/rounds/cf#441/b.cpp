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

void solve(lli arr[], lli n, lli k, lli m){
	
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,k,m;
	cin>>n>>k>>m;
	lli arr[n];
	c = 0;
	mlli ma;
	map<lli,vector<lli> > nu;
	rep(i,n){
		cin>>arr[i];
		ma[arr[i]%m]++;
		nu[arr[i]%m].pb(arr[i]);
	}
	mlli::iterator it;
	for (it = ma.begin(); it != ma.end(); it++){
		if(it->second >= k){
			cout<<"Yes"<<endl;
			y = 0;
			for(lli x:nu[it->first]){
				if(y == k) break;
				cout<<x<<" ";
				y++;
			}
			cout<<endl;
			bye;
		}
	}
	cout<<"No"<<endl;
	bye;
}

