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

int main(){
	ios_base::sync_with_stdio(0);
	long double t,n,d,e,f,x,y,m,s;
	lli a,b,h,c;
	cin>>h;
	cin>>m>>s;
	cin>>a>>b;
	a%=12;
	b%=12;
	h%=12;
	f = m;
	m /= 5;
	s /= 5;
	long double arr[3];
	// arr[0] = fmod(0.5*(60*h+m), 60);
	// arr[0] = ((0.5)*(60*h+m))/360;
	arr[0] = ((60*h)+f)/60;
	arr[1] = m;
	arr[2] = s;
	lli ac = 0,bc = 0;
	lli mi = min(a,b);
	lli ma = max(a,b);
	c = 0;
	rep(i,3){
		if(arr[i] > mi && arr[i] < ma){
			c++;
		}
	}
	if(c == 3 || c==0){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	bye;
}

