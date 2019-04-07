#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <cstring>
#include <string>
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
	lli N, K, E, M,t;
	cin>>t;
	while(t--){
		cin>>N>>K>>E>>M;
		lli sum[N-1];
		memset(sum,0,sizeof sum);
		for (int i=0; i<N-1; i++) {
			for (int j=0; j<E; j++) {
				int x; cin>>x;
				sum[i] += x;
			}
		}
		lli own = 0;
		for (int i=0; i<E-1; i++) {
			int x; cin>>x;
			own += x;
		}
		sort(sum, sum+N-1);
		own = sum[N-K-1] - own + 1;
		if (own <= 0) cout << 0<<endl;
		else if (own <= M) cout << own<<endl;
		else cout << "Impossible"<<endl;
		}
	bye;
}
