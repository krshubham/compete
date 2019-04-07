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
lli mulmod(lli a, lli b, lli mod){
	lli res = 0;
	a = a % mod;
	while (b > 0){
		if (b % 2 == 1){
			res = (res + a) % mod;
		}
		a = (a * 2) % mod;
		b /= 2;
	}
	return res % mod;
}


int main(){
	int t,n,a,b,c,d,e,f,x,y,k,g;
	// string s(2000,'x');
	string s;
	cin>>s;
	cin>>t;
	string test = "";
	vector<string> v;
	for (int i = 0; i < s.size(); i++) {
		string temp = "";
		for (int j = i; j < s.size(); ++j){
			temp += s[j];
			v.pb(temp);
		}
	}
	sort(all(v));
	rep(i,v.size()){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	vlli indices;
	indices.pb(v[0].size());
	for (int i = 1; i < v.size(); ++i){
		indices.pb(v[i].size()+indices[i-1]);
	}
	// rep(i,indices.size()){
	// 	cout<<indices[i]<<" ";
	// }
	k = 0;
	g = 0;
	while(t--){
		cin>>a>>b;
		k = mulmod(a,g,b)+1;
		cout<<k<<endl;
		vlli::iterator it = upper_bound(all(indices),k);
		it--;
		for (int i = *it; i <= v[*it].size(); ++i){
			if(v[i] == k){
				
			}
		}
		// g += test[k-1];
	}
	bye;
}