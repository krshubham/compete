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
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828
#define stp(a,b) a.push(b)
#define all(a) a.begin(),a.end()
#define PI 3.1415926535897932384626433832795

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

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

lli sum = 0,gsum = INT_MAX;
lli t,n,a,b,c,d,e,f,x,y,m,k;
vlli v,vp,ind,si;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k;
	c = 0;
	d = 1;
	lli start = 0;
	for (int i = 0; i < n; ++i){
		cin>>x;
		if(x == 1) {
			vp.pb(i - start);
			c++;
			ind.pb(i);
			si.pb(i);
			start = i;
		}
		v.pb(x);
	}
	if(c < m) cout<<"-1"<<endl;
	else if(c == m){
		for (int i = 0; i < c; ++i){
			if(i == 0){
				sum += vp[i]*d;
			}
			else{
				sum += k*vp[i]*d;
				d++;
			}
		}
		cout<<sum<<endl;
	}
	else{
		for (int i = 0; i <= c-m; ++i){
			y = i;
			e = 0;
			sum = 0;			
			while(e < m){
				if(e == 0){
					sum += si[y];
					e++;
				}
				else if(e >= 1){
					sum += vp[y]*e*k;
					e++;
				}
				y++;
			}
			gsum = min(sum,gsum);
		}
		cout<<gsum<<endl;
	}
	bye;
}

