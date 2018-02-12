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
 
const lli MAXN = 2e6+10;
 
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
 
bool cmp(plli a, plli b){
	return a.first<b.first;
}
 
lli nextPowerOf2(lli n){
	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n++;
	return n;
}
//acting as a map.speed
lli m[MAXN] = {0};
lli tree[4*MAXN];
lli arr[MAXN];
 
void build(lli arr[], lli tree[], lli start, lli end, lli node) {
	if (start == end) {
		tree[node] = 1;
		return;
	}
	lli mid = (start + end) / 2;
	build(arr, tree, start, mid, 2 * node);
	build(arr, tree, mid + 1, end, 2 * node + 1);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
 
void update(lli arr[], lli tree[], lli start, lli end, lli node, lli idx, lli val, lli n) {
	if(arr[idx]<=0)
		return;
	if(idx> n-1)
		return;
	if (start == end) {
		arr[idx] -= val;
		tree[node] = (arr[idx]<=0)?0:1;
		return;
	}
	lli mid = (start + end) / 2;
	if (idx > mid) {
		update(arr, tree, mid + 1, end, 2 * node + 1, idx, val,n);
	} else {
		update(arr, tree, start, mid, 2 * node, idx, val,n);
	}
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
 
int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	d = 0;
	rep(i,n){
		cin>>arr[i];
		if(arr[i] == 1){
			d++;
		}
	}
	build(arr,tree,0,n-1,1);
	cin>>t;
	unordered_set<lli> st;
	c = n;
	while(t--){
		cin>>x>>y;
		bitset<17> bit(x);
		// cout<<bit<<endl;
		unsigned long zz = bit.to_ulong();
		lli kuchbhi = nextPowerOf2(zz);
		if(kuchbhi != zz){
			if(m[zz] == 1 || m[nextPowerOf2(zz)-1] == 1){
				cout<<c<<endl;
				continue;
			}
		}
		queue<string> q;
		string str = bit.to_string();
		replace(all(str), '1', '?');
		q.push(str);
		lli ans = INT_MAX;
		while (!q.empty()){
			string str = q.front();
			size_t index = str.find('?');
			if(index != string::npos){
				str[index] = '0';
				q.push(str);
				str[index] = '1';
				q.push(str);
			}
			else{
				bitset<17> bits(str);
				unsigned long z = bits.to_ulong();
				m[z] = 1;
				if(z < n){
					// cout<<z<<" ";
					st.insert(z);
					update(arr, tree, 0, n-1, 1, z, y,n);
				}
			}
			q.pop();
		}
		c = tree[1];
		cout<<tree[1]<<endl;
		// cout<<c<<" "<<tree[1]<<endl;
	}
	bye;
} 