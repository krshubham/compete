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

const long long MAX_SIZE = 1000001;

vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);

inline void manipulated_seive(int N){

	isprime[0] = isprime[1] = false ;
	for (long long int i=2; i<N ; i++){
		if (isprime[i]){
			prime.push_back(i);
			SPF[i] = i;
		}
		for (long long int j=0;j < (int)prime.size() && i*prime[j] < N && prime[j] <= SPF[i];j++){
			isprime[i*prime[j]]=false;
			SPF[i*prime[j]] = prime[j] ;
		}
	}
}


long double solve(lli x){
	lli result = 1;
	for (int i=2; i<=sqrt(x); i++){
		if (x%i==0){
			if (i==(x/i))
				result += i;
			else
				result += (i + x/i);
		}
	}
	long double res;
	res = (long double)result/(long double)x;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	manipulated_seive(MAX_SIZE);
	cin>>x>>y;
	if(x == 1 || y == 1){
		cout<<1<<endl;
		bye;
	}
	pair<lli,long double> ans = mp(INT_MAX,(long double)INT_MAX);
	a = 0;
	for (int i = y; i >= x; --i){
		if(isprime[i]){
			ans = mp(i,0);
			break;
		}
		else{
			long double tes = solve(i);
			if(ans.second > tes){
				ans = mp(i,tes);
			}
		}
	}
	if(a == 0)
		cout<<ans.first<<endl;
	bye;
}

