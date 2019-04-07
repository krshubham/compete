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

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	lli oc=0,tc=0,thc=0,fc=0,count=0,sum=0;
	for (int i = 0; i < t; ++i){
		cin>>a;
		if(a == 1)
			oc++;
		else if(a == 2)
			tc++;
		else if(a==3)
			thc++;
		else if(a == 4)
			fc++;
	}
	count+=fc;
	count+=thc;
	if(oc > thc){
		oc -=thc;
	}
	else if(oc < thc){
		oc = 0;
	}
	else if(oc == thc){
		oc = 0,thc=0;
	}
	count += ceil(double(oc+(tc*2))/4.0);
	cout<<count<<endl;
	bye;
}

