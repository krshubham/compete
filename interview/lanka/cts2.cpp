#include <iostream> 
#include <map>
#include <vector>
#include <algorithm>
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

typedef long long int lli;
typedef vector<lli> vlli;

typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;


int main(){
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	map<lli,vlli> m;
	rep(i,n){
		cin>>x>>y;
		m[x].pb(y);
	}
	map<lli,vlli>::iterator it;
	c = 0;
	a = 0;
	for (it = m.begin(); it != m.end(); it++){
		a = max(a,(lli)it->second.size());
	}
	lli ans1,any1,ans2,any2;
	for (it = m.begin(); it != m.end(); it++){
		if(it->second.size() == a){
			sort(all(it->second));
			if((it->second[it->second.size()-1] - it->second[0]) > c){
				ans1 = it->first;
				ans2 = it->first;
				any1 = it->second[0];
				any2 = it->second[it->second.size()-1];
				c = it->second[it->second.size()-1] - it->second[0];
			}
		}
	}
	cout<<ans1<<endl;
	cout<<any1<<endl;
	cout<<ans2<<endl;
	cout<<any2<<endl;
	bye;
}

