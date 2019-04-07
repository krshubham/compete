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

/**
from 1 to 4	few
	from 5 to 9	several
	from 10 to 19	pack
	from 20 to 49	lots
	from 50 to 99	horde
	from 100 to 249	throng
	from 250 to 499	swarm
	from 500 to 999	zounds
	from 1000	legion
*/

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	if(n <= 4) cout<<"few"<<endl;
	else if(n <= 9) cout<<"several"<<endl;
	else if(n <= 19) cout<<"pack"<<endl;
	else if(n <= 49) cout<<"lots"<<endl;
	else if(n <= 99) cout<<"horde"<<endl;
	else if(n <= 249) cout<<"throng"<<endl;
	else if(n <= 499) cout<<"swarm"<<endl;
	else if(n <= 999) cout<<"zounds"<<endl;
	else cout<<"legion"<<endl;
	bye;
}

