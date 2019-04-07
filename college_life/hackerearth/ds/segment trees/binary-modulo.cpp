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

const lli MAXN = 1e5+5;

lli arr[MAXN];
lli tree[4*MAXN];

void update(lli node, lli start, lli end, lli idx, lli val){
	if(start == end){
		arr[idx] += val;
		tree[node] += val;
	}
	else{
		lli mid = (start + end) / 2;
		if(start <= idx and idx <= mid){
			update(2*node, start, mid, idx, val);
		}
		else{
			update(2*node+1, mid+1, end, idx, val);
		}
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}


void build(lli node, lli start, lli end){
	if(start == end){
		tree[node] = arr[start];
	}
	else{
		lli mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = tree[2*node] + tree[2*node+1];
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
	return (p1 + p2);
}


int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	// build(1,1,n,tree,a);
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		rep(i,s.size()){
			arr[i] = s[i] - '0';
		}
		build(1,1,s.size());
		cout<<tree[1]<<endl;
		// update(1,1,n,x,y,tree,a);
	}
	bye;
}

