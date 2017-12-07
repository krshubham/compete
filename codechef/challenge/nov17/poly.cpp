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

typedef struct poly{
	lli a,b,c,d;
	poly(lli a, lli b,lli c,lli d){
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	lli solve(lli x){
		lli ans = ((this->a) + (this->b)*(x) + (this->c)*(x*x) + (this->d)*(x*x*x));
		return ans;
	}
} Poly;

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,q;
	cin>>t;
	while(t--){
		cin>>n;
		vector<Poly*> v;
		rep(i,n){
			cin>>a>>b>>c>>d;
			Poly *poly = new Poly(a,b,c,d);
			v.pb(poly);
		}
		cin>>q;w
		while(q--){
			cin>>x;
			c = INT_MAX;
			for (int i = 0; i < n; ++i){
				c = min(v[i]->solve(x),c);
			}
			cout<<c<<endl;
		}
	}
	bye;
}

