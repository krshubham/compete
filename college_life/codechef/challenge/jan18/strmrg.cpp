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

string process(string s){
	char c='*';
	string h;
	for(int i=0;i<s.size();i++){
		if(s[i]!=c){
			c=s[i];
			h+=c;
		}
	}
	return(h);
}

const lli MAXN = 5e3+5;

lli dp[MAXN][MAXN]={0};

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,c,d,e,f,x,y,m;
	cin>>t;
	string a,b;
	while(t--){
		cin>>m>>n;
		cin>>a>>b;
		a=process(a);
		b=process(b);
		// cout<<a<<" "<<b<<endl;
		c = INT_MAX;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(a[j]==b[i]){
					dp[i+1][j+1]=dp[i][j]+1;
				}
				else{
					dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
				}
			}
		}
		cout<<(b.size()-dp[b.size()][a.size()]+a.size())<<endl;
	}
	bye;
}
