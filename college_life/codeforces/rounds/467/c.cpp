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

inline vector<string> split(string str,string sep){char* cstr=const_cast<char*>(str.c_str());char* current;vector<string> arr;current=strtok(cstr,sep.c_str());while(current!=NULL){arr.push_back(current);current=strtok(NULL,sep.c_str());}return arr;}
inline bool isPrime(lli n){if (n <= 1){return false;}if (n <= 3)  {return true;}if (n%2 == 0 || n%3 == 0) {return false;}for (int i=5; i*i<=n; i=i+6){if (n%i == 0 || n%(i+2) == 0){return false;}}return true;}
inline lli power(lli x,lli y,lli p){int res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y = y>>1;x = (x*x) % p;}return res;}


long double k,d,t,z,interval,warm,yo,mo,ans;

void solve(){
	if(t<k){
		cout<<t<<endl;
		exit( 0);
	}
	if((lli)k%(lli)d==0){
		cout<<t<<endl;
		exit( 0);
	}

	z = k/d;
	z++;
	interval = static_cast<long double>(((lli)(z))*d);
	warm = interval-k;
	if(d>k){
		warm = d-k;
	}
	yo = static_cast<long double>(k + (static_cast<long double>(warm/(2.0)))+0.0);

	if(t<=yo){
		cout<<static_cast<long double>(static_cast<long double>(k) + ((t-k)*2.0));
		exit( 0);
	}
}

void This(){
	mo = t/yo;
	mo = (lli)(mo);
	ans=0.0;
	ans = ans + static_cast<long double>(mo*k) + static_cast<long double>(mo*warm);
	t = t - static_cast<long double>(mo*yo);
}


int main(){
	cin>>k>>d>>t;
	cout<<fixed<<setprecision(15);
	solve();
	This();
	if(t<=k){
		ans = ans + t;
		cout<<ans<<endl;
		return 0;
	}
	else{
		ans = ans + (static_cast<long double>(k) + (t-k)*2.0);
		cout<<ans<<endl;
		return 0;
	}
	bye;
}

