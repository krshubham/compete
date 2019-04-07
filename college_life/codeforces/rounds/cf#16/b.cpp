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


typedef struct obj{
	int a,b;
} obj;

bool comp(obj x,obj y){
	return x.b>y.b;
}

int main(){
	ios_base::sync_with_stdio(0);
	int n,r;
	cin>>n>>r;
	obj x[r];
	for(int i=0;i<r;++i){
		cin>>x[i].a>>x[i].b;
	}
	sort(x,x+r,comp);
	int i=0,cnt=0,res=0;
	while((cnt!=n) && (i<r)){
		cnt+=x[i].a;
		res+=(x[i].a*x[i].b);
		if(cnt>n){
			res-=(cnt-n)*(x[i].b);
			cnt=n;
		}
		++i;
	}
	cout<<res<<endl;
	return 0;
}