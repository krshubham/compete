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
#define e_val 2.718281828

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef vector<pair<lli,lli> > vplli;

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
		lli arr[n];
		for (int i = 0; i < n; ++i){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		x = 1;
		lli count  = 0;
		vplli v;
		for (int i = n-1; i > 0; i--){
			if(arr[i] == arr[i-1]){
				v.pb(mp(arr[i],arr[i-1]));
				i--;
			}
		}
		if(v.size() < 2) cout<<-1<<endl;
		else
			cout<<v[0].first*v[1].first<<endl;
	}
	bye;
}
