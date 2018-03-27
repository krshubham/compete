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
#define MAXN 100005
lli arr[MAXN];
lli tree[4*MAXN];

void build(lli node, lli start, lli end){
	if(start == end){
		tree[node] = arr[start];
	}
	else{
		lli mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node] = min(tree[2*node],tree[2*node+1]);
	}
}

void update(lli node, lli start, lli end, lli idx, lli val){
	if(start == end){
		arr[idx] = val;
		tree[node] = val;
	}
	else{
		lli mid = (start + end) / 2;
		if(start <= idx and idx <= mid){
			update(2*node, start, mid, idx, val);
		}
		else{
			update(2*node+1, mid+1, end, idx, val);
		}
		tree[node] = min(tree[2*node], tree[2*node+1]);
	}
}

lli query(lli node, lli start, lli end, lli l, lli r){
	if(r < start or end < l){ 
		return 0;
	}
	if(l <= start and end <= r){
		return tree[node];
	}
	lli mid = (start + end) / 2;
	lli p1 = query(2*node, start, mid, l, r);
	lli p2 = query(2*node+1, mid+1, end, l, r);
	return min(p1,p2);
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,q;
	cin>>n>>q;
	char cc;
	for (int i = 1; i <= n; ++i){
		cin>>arr[i];
	}
	while(q--){
		cin>>cc>>x>>y;
		if(cc=='q'){
			lli c = query(1,1,n,x,y);
			cout<<c<<endl;
		}
		else{
			update(1,1,n,x,y);
		}
	}
	bye;
}

