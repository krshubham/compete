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

lli r[501], c[501], d1, d2, res;

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,d,e,f,x,y,xx;
	cin >> n;
	if (n == 1) {
		cout << 1<<endl;
		bye;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> xx;
			r[i] += xx;
			c[j] += xx;
			if (i == j) d1 += xx;
			if (i == n + 1 - j) d2 += xx;
			if (xx == 0) x = i, y = j;
		}
	}
	r[0] = r[n];
	res = r[x - 1] - r[x];
	if (res <= 0) {
		cout<<-1<<endl;
		bye;
	}
	r[x] += res;
	c[y] += res;
	if (x == y) {
		d1 += res;
	}
	if (x == n + 1 - y){
		d2 += res;
	}
	for (int i = 1; i <= n; i++){
		if (r[i] != r[x] || c[i] != r[x]){
			cout<<-1<<endl;
			bye;
		}
	}
	if (d1 != r[x] || d2 != r[x]){
		cout<<-1<<endl;
		bye;
	}
	cout<<res<<endl;
	bye;
}
