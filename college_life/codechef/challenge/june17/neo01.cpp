#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;

inline bool isPrime(lli n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
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
	while(t--){
		cin>>n;
		vlli neg;
		a=0,b=0,c=0,d=0;
		for (int i = 0; i < n; ++i){
			cin>>e;
			if(e >= 0){
				a+=e;
				b++;
			}
			else{
				neg.pb(e);
			}
		}
		sort(neg.rbegin(),neg.rend());
		d = a*b;
		for (int i = 0; i < neg.size(); ++i){
			x = (a+neg[i])*(b+1);
			if(d < x){
				d = x;
				a += neg[i];
				b++;
			}
			else{
				c += neg[i];
			}
		}
		cout<<c+d<<endl;
	}
	bye;
}
