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

vlli accumulate(vlli& nums) {
	lli n = nums.size();
	vlli sums(n + 1, 0);
	for (lli i = 1; i <= n; i++) 
		sums[i] = nums[i - 1] + sums[i - 1];
	return sums;
}

lli upper_bound(vlli& sums, lli left, lli right, lli target) {
	lli l = left, r = right;
	while (l < r) {
		lli m = l + ((r - l) >> 1);
		if (sums[m] <= target) l = m + 1;
		else r = m;
	}
	return sums[r] > target ? r : -1;
}

lli minSubArrayLen(lli s, vlli& nums) {
	vlli sums = accumulate(nums);
	lli n = nums.size(), minlen = INT_MAX;
	for (lli i = 1; i <= n; i++) { 
		if (sums[i] >= s) {
			lli p = upper_bound(sums, 0, i, sums[i] - s);
			if (p != -1) minlen = min(minlen, i - p + 1LL);
		}
	}
	return minlen == INT_MAX ? -1 : minlen;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		cin>>n>>x;
		vlli v(n);
		rep(i,n){
			cin>>v[i];
		}
		cout<<minSubArrayLen(x,v)<<endl;
	}
	bye;
}

