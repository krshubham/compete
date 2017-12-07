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
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )
#define endl '\n'
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef unsigned long long ull;
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
lli arr[100005];
plli tree[4*200005];

void build(lli node, lli start, lli end){
	if(start == end){
		tree[node].first = arr[start];
		tree[node].second = (floor(log2(arr[start]))+1 - __builtin_popcount(arr[start]));
	}
	else{
		lli mid = (start+end)/2;
		build(2*mid,start,mid);
		build(2*mid + 1, mid+1,end);
		tree[node].first = tree[2*node].fi^tree[2*node+1].fi;
		tree[node].second = tree[2*node].se + tree[2*node+1].se;
	}
}

plli query(lli node, lli start, lli end, lli l, lli r){
	if(l > end || r < start){
		return mp(-1,-1);
	}
	if(l <= start && end >= r){
		return tree[node];
	}
	lli mid = (start+mid)/2;
	plli p1 = query(2*node,start, mid, l, r);
	plli p2 = query(2*node+1, mid+1, end, l, r);
	return mp((p1.fi + p2.fi),(p1.se+p2.se));
}


int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	for (int i = 1; i <= n; ++i){
		cin>>arr[i];
	}
	build(1,1,n);
	cin>>t;
	while(t--){
		cin>>a>>b;
		// c = 0;
		// for (int i = a-1; i < b; ++i){
		// 	if(i == a-1){
		// 		x = arr[i];
		// 	}
		// 	else x^=arr[i];
		// 	if(arr[i] == 0) c+=1;
		// 	else{
		// 		c += (floor(log2(arr[i]))+1 - __builtin_popcount(arr[i]));
		// 	}
		// }
		// cout<<x<<" "<<c<<endl;
		plli ans = query(1,1,n,a,b);
		cout<<ans.fi<<" "<<ans.se<<endl;
	}
	bye;
}

