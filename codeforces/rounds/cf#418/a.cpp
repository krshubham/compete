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
	cin>>a>>b;
	lli arr[a],br[b];
	for (int i = 0; i < a; ++i){
		cin>>arr[i];
	}
	for (int i = 0; i < b; ++i){
		cin>>br[i];
	}
	if(b >= 2){
		cout<<"Yes"<<endl;
	}
	else if(b == 1){
		lli l = 0, h = a-1;
		while(l < h){
			if(arr[h] == 0){
				h--;
			}
			else if(arr[l] == 0){
				l++;
			}
			if(arr[h] < arr[l]){
				cout<<"Yes"<<endl;
				f = 1;
				break;
			}
			l++;
			h--;
		}
		if(f != 1){
			cout<<"No"<<endl;
		}
	}
	bye;
}
