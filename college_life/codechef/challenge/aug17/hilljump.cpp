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

inline lli solve(lli b, lli c, vlli v, lli n){
	lli index = b;
	while(c>0){
		if(v[index] > v[index-1]){
			c--;
			index++;
		}
		else{
			bool fl = false;
			for (int i = index-1; i < min(n,index+(lli)100); i++){
				if(v[i] > v[index-1]){
					index = i+1;
					c--;
					fl = true;
					break;
				}
			}
			if(fl == false){
				break;
			}
		}
	}
	return index;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,q;
	cin>>n>>q;
	vlli v(n);
	for (int i = 0; i < n; ++i){
		cin>>v[i];
	}
	while(q--){
		cin>>a;
		if(a == 1){
			cin>>b>>c;
			cout<<solve(b,c,v,n)<<endl;
		}
		else if(a == 2){
			cin>>b>>c>>d;
			for (int i = b-1; i < c; i++){
				v[i] += (d);
			}
		}
	}
	bye;
}

