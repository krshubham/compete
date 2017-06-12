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
typedef map<lli,lli> mlli;
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
	cin>>n;
	lli arr[n],br[n],cr[n];
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}
	x = 0;
	vlli v;
	for (int i = 0; i < n; ++i){
		cin>>br[i];
		if(br[i] == arr[i]){
			cr[i] = arr[i];
		}
		else{
			x++;
			v.pb(i);
		}
	}
	for (int i = 0; i < n; ++i){
			cr[i] = arr[i];
	}
	if(x == 1){
		for (int i = 1; i <= n; ++i){
			if(find(arr,arr+n,i) != arr+n && find(br,br+n,i) != br+n){
				continue;
			}
			else{
				cr[v[0]] = i;
				break;
			}
		}
	}
	else if(x >= 2){
		y = 1;
		for (int i = 0; i < v.size(); ++i){
			if(isEven(y)){
				cr[v[i]] = arr[v[i]];
			}
			else{
				cr[v[i]] = br[v[i]];
			}
			y++;
		}
	}
	for (int i = 0; i < n; ++i){
		cout<<cr[i]<<" ";
	}
	cout<<endl;
	bye;
}
