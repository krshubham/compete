#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <iomanip>
#include <stack>
#include <climits>
#include <queue>
#include <string>
#include <cstring>
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

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
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

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}

int wrongSolver(std::vector <unsigned int> a) {
	int n = a.size();
	std::vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
		if (prefSum[i] < a[i]) {
			printf("%d %u\n", i, prefSum[i]);
		}
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	unsigned int mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	return where;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli a,b,c,d,e,f,g,x,y,t,n;
	cin>>t;
	while (t--) {
		cin>>n;  
		vector<unsigned int> a(n);
		int r = 0, w = 0;
		ll S = n;
		lli modulo = 1ll << 32;
		a[0] = 1;
		c = 1;
		for (int i = 1; i < S - 1; ++i) {
			a[i] = modulo / (S - 1);
			c += a[i];
		}
		a[a.size() - 1] = modulo - c - 2;
		
		while (100000 < a.back()) {
			for (int i = 1; i < a.size() - 1; ++i) {
				a[i]++;
			}
			a[a.size() - 1] -= a.size() - 1;
		}
		c = modulo - 2;
		a[0] = 1; 
		for (int i = 0; i < S; ++i) {
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}