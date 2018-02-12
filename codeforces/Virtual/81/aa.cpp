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

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,d,e,f,x,y;
	long double c;
	cin>>a>>b>>c;
	string s;
	mslli m;
	rep(i,a){
		cin>>s>>x;
		long double ld = (long double)x*c;
		if((lli)ld >= 100){
			m[s] = ld;
		}
	}
	set<pair<string,lli> > v;
	rep(i,b){
		cin>>s;
		v.insert(mp(s,m[s]));
	}
	mslli::iterator it = m.begin();
	for(; it != m.end(); it++){
		if(it->second >= 100){
			v.insert(mp(it->first, it->second));
		}
	}
	cout<<v.size()<<endl;
	set<pair<string, lli>>::iterator itt = v.begin();
	for(; itt != v.end(); itt++){
		cout<<itt->first<<" "<<itt->second<<endl;
	}
	bye;
}

