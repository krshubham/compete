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
mlli dp;
lli fib_bottom_up(lli n){
	if(n <= 1) return n;
	if(dp[n] != 0) return dp[n];
	dp[n] = fib_bottom_up(n-1) + fib_bottom_up(n-2);
	return dp[n];
}
mlli tddp;
lli fib_top_down(lli n){
	tddp[0] = 0;
	tddp[1] = 1;
	for (int i = 2; i <= n; ++i){
		tddp[i] = tddp[i-1] + tddp[i-2];
	}
	return tddp[n];
}

void multiply(lli F[2][2], lli M[2][2]){
	lli x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
	lli y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
	lli z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
	lli w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(lli F[2][2], lli n){
	if( n == 0 || n == 1)
		return;
	lli M[2][2] = {{1,1},{1,0}};

	//need to understand this properly
	power(F, n/2);
	multiply(F, F);

	if (n%2 != 0)
		multiply(F, M);
}

lli fibo_matrix(lli n){
	lli mat[2][2] = {{1,1},{1,0}};
	if(n == 0) return 0;
	power(mat,n-1);
	return mat[0][0];
}


int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<fibo_matrix(n+2)<<endl;
	}
	bye;
}

