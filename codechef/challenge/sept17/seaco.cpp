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
// #include <bits/stdc++.h>//doesn't work in mac
using namespace std ;

#define bye return 0
#define pb push_back
#define mp make_pair
#define e_val 2.718281828
#define stp(a,b) a.push(b)
#define all(a) a.begin(),a.end()
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
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


ll build( int q, int l, int r, int pos, ll tree[] ){
	if( l > r ) return 0;
	if( q < l || q > r ) return 0;
	if( l == r ) { 
		tree[pos] = tree[pos] + 1;
		tree[pos] %= mod;
		return tree[pos];
	}
	int m = (l+r)/2;
	tree[pos] = build( q, l, m, pos*2+1, tree )%mod + build( q, m+1, r, pos*2+2, tree )%mod;
	tree[pos] %= mod;
	return tree[pos];
}

int query( int q, int l, int r, int pos, ll tree[], ll lazy[] ){
	if( q < l || q > r ) return 0;
	if( l == r ){ 
		ll a = (tree[pos]%mod+lazy[pos]%mod)%mod;
		return a;
	}
	int m = l + (r-l)/2;
	ll ans = lazy[pos]%mod + query( q, l, m, pos*2+1, tree, lazy )%mod + query( q, m+1, r, pos*2+2, tree, lazy )%mod;
	ans %= mod;
	return ans;
}


void update( int ql, int qr, int l, int r, int pos, ll tree[], ll lazy[], int cnt ){
	if( qr < l || ql > r ) return;
	if( l >= ql && r <= qr ){ lazy[pos] = (lazy[pos]%mod + cnt%mod)%mod; return; }
	int m = (l+r)/2;
	update( ql, qr, l, m, pos*2+1, tree, lazy, cnt );
	update( ql, qr, m+1, r, pos*2+2, tree, lazy, cnt );
}

int main(){
	ios_base::sync_with_stdio(0);
	lli a,b,c,d,x,y;
	lli t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll tree[4*m];
		ll lazy[4*m];
		fill(tree,tree+(4*m),0);
		fill(lazy,lazy+(4*m),0);
		vector<int> tt;
		vector<pair<int,pair<int,int> > > q;
		rep(j,m){
			int t,l,r;
			cin>>t>>l>>r;
			l--; r--; 
			q.pb(mp(t,mp(l,r)));
			if( t == 2 ){ tt.pb(j); }
			build( j, 0, m-1, 0, tree );
		}

		rrep(j,tt.size()){
			// rep(k,m){
			// 	cout << query( k, 0, m-1, 0, tree, lazy) << " ";
			// }
			// cout << endl;
			// bye
			ll cnt = query( tt[j], 0, m-1, 0, tree, lazy );
			ll l,r;
			l = q[tt[j]].second.first;
			r = q[tt[j]].second.second;
			update( l, r, 0, m-1, 0, tree, lazy, cnt );

		}
		
		ll times[m];
		fill(times,times+m,0);
		rep(j,m){
			// cout<<query( j, 0, m-1, 0, tree, lazy )<<" ";
			times[j] = query( j, 0, m-1, 0, tree, lazy );
		}
		cout<<endl;
		bye;
		ll val = 0;
		ll carr[n+4];
		memset(carr,0,sizeof(carr));
		rep(j,m){
			if(q[j].first == 2) continue;
			carr[q[j].second.first] += times[j];
			carr[q[j].second.first] %= mod;
			carr[q[j].second.second+1] -= times[j];
			if( carr[q[j].second.second+1] < 0 ){
				carr[q[j].second.second+1] += mod;
			}
			carr[q[j].second.second+1] %= mod;
		}

		rep(j,n){
			val = (val%mod + carr[j]%mod)%mod;
			cout<<val<<" ";
		}
		cout<<endl;
	}		
	bye;
}
