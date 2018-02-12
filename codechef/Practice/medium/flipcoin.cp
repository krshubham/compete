#pragma comment (linker, "/stack:20000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define endl '\n'

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef unsigned long long ull;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef unordered_map<lli,lli> umlli;
typedef vector<pair<lli,lli> > vplli;

vector<string> split(string str,string sep){
	char* cstr=const_cast<char*>(str.c_str());
	char* current;
	vector<string> arr;
	current=strtok(cstr,sep.c_str());
	while(current!=NULL){
		arr.push_back(current);
		current=strtok(NULL,sep.c_str());
	}
	return arr;
}

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

lli A[100000] = {0};
lli tree[262144] = {0};
lli lazy[262144] = {0};
lli N,Q,x,y,z;

void update(lli node, lli start, lli end, lli l, lli r){
	if(lazy[node]!=0){
		if(lazy[node]&1){
			tree[node] = (end-start+1) - tree[node] ;
			if(start!=end) { lazy[node*2]+=lazy[node]; lazy[node*2+1]+=lazy[node];}
		}
		lazy[node] = 0;
	}

	if (start>end || start>r || end<l) return;

	if ( l<=start && end<=r ){
		tree[node] = (end-start+1) - tree[node];
		if(start!=end){
			lazy[node*2]++;
			lazy[node*2+1]++;
		}
		return;
	}
	lli mid = (start+end) / 2;
	update(node*2, start, mid, l, r);
	update(node*2+1, mid+1, end, l, r);
	tree[node] = tree[node*2] + tree[node*2+1];
}

lli query(lli node, lli start, lli end, lli l, lli r){
	if( start>end || start>r || end<l) return 0;
	if(lazy[node]!=0){
		if(lazy[node]&1) tree[node] = (end-start+1)-tree[node];
		if(start!=end){lazy[node*2]+=lazy[node]; lazy[node*2+1]+=lazy[node];}
		lazy[node] = 0;
	}
	if(start>=l && end<=r) return tree[node];
	lli mid = (start+end)/2;
	return(query(node*2,start,mid,l,r)+query(node*2+1,mid+1,end,l,r));
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,m;
	cin >> N >> Q;
	while(Q--) {
		cin >> x >> y >> z;
		if(x==0) {
			update(1,0,N-1,y,z);
		}
		else{ 
			cout << query(1,0,N-1,y,z) << endl;
		}
	}
	bye;
}

