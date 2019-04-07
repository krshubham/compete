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
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )
#define endl '\n'
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define MAXN 100005
#define SQRSIZE 100

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

/**
We have two types of queries:
U x y : Update the value of number at index x to y
Q l r: Find the range sum from the index l to r
I know segment tree is the fastest approach here, but let's give sqrt decomposition a shot.
*/
lli arr[MAXN];
lli block[SQRSIZE];
lli bs;

void update(lli x, lli y){
	lli block_num = x/bs;
	block[block_num] += y - arr[x-1];
	arr[x-1] = y;
}


lli query(lli l, lli r){
	lli sum = 0;
	while (l<r and l%bs!=0 and l!=0){
		sum += arr[l];
		l++;
	}
	while (l+bs <= r){
		sum += block[l/bs];
		l += bs;
	}
	while (l<=r){
		sum += arr[l];
		l++;
	}
	return sum;
}


void preprocess(lli n){
	lli bp = -1;
	bs = sqrt(n);
	for (int i = 0; i < n; ++i){
		if(i%bs == 0){
			bp++;
		}
		block[bp] += arr[i];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	rep(i,n){
		cin>>arr[i];
	}
	preprocess(n);
	cout<<query(3,8)<<endl;
	bye;
}

