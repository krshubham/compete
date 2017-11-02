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

bool cmp(plli &a, plli &b) {
	return a.first<b.first;
}

int main() {
	lli n = 0,t = 0;
	lli c = 0,s = 0;
	cin>>n>>t;
	vplli houses;
	for(int i = 0; i<n; ++i) {
		cin>>c>>s;
		houses.pb(mp(c, s));
	}
	sort(houses.begin(), houses.end(), cmp);
	lli res = 0;

	for(int i = 0; i<n-1; ++i) {
		lli dist = houses[i+1].first-houses[i].first;
		dist *= 2;
		dist -= houses[i].second+ houses[i+1].second;
		if(dist > 2*t) {
			res += 2;
		}
		else if(dist == 2*t) {
			res += 1;
		}
	}

	res += 2;
	cout<<res<<endl;
	return 0;
}