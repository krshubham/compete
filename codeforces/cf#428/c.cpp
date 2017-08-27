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
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828

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

typedef struct node{
	vlli children;
	set<lli> parents;
} node;

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	map<lli,node> m;
	map<lli, node>::iterator mit;
	set<lli>::iterator it;
	for (int i = 0; i < t-1; ++i){
		cin>>a>>b;
		m[a].children.pb(b);
		m[b].parents.insert(a);
		for (it = m[a].parents.begin(); it!=m[a].parents.end(); it++){
			m[b].parents.insert(*it);
		}
	}
	long double sum = 0,cnt = 0;
	for (mit = m.begin(); mit != m.end();mit++){
		if(mit->second.children.size() == 0){	
			cnt++;
		}
	}
	for (mit = m.begin(); mit != m.end();mit++){
		if(mit->second.children.size() == 0){
			sum+=(double)mit->second.parents.size()/cnt;
		}
	}
	cout<<fixed<<setprecision(15)<<sum<<endl;
	bye;
}

