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

unordered_map<lli,lli> m;
bool cmp(lli a, lli b){
	int x = __builtin_popcount(a);
	int y = __builtin_popcount(b);
	if(x == y){
		return m[a] < m[b];
	}
	else return x < y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		cin>>n;
		lli arr[n];
		rep(i,n){
			cin>>arr[i];
			m[arr[i]] = i;
		}
		sort(arr,arr+n,cmp);
		rep(i,n){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	bye;
}

