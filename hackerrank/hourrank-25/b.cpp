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
	lli t,n,a,b,c,d,e,f,x,y;
	string s;
	cin>>s;
	cin>>t;
	while(t--){
		cin>>a>>b;
		string ss = s.substr(a-1,b-a+1);
		// cout<<ss<<endl;
		map<char,lli> m;
		for(char i:ss){
			m[i]++;
		}
		map<char,lli>::iterator it = m.begin();
		lli oc = 0,ec=0,mco=0;
		c = 0;
		for(; it != m.end(); it++){
			if(it->second&1){
				oc++;
				mco = max(mco,it->second);				
			}
			else{
				ec++;
				c += it->second;
			}
		}
		x = 0;
		for(it = m.begin(); it != m.end(); it++){
			if(it->second == mco){
				x++;
			}
		}
		if(x == 0){
			if(ec == 1){
				cout<<1<<endl;
			}
			else{
				cout<<fact(ec)<<endl;
			}
		}
		else{
			cout<<x<<endl;
		}
	}
	bye;
}

