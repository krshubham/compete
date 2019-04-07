#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <string>
#include <cstdio>
#include <cstring>
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
	if (n <= 1) {
		return false;
	}
	if (n <= 3)  {
		return true;
	}

	if (n%2 == 0 || n%3 == 0) {
		return false;
	}

	for (int i=5; i*i<=n; i=i+6){
		if (n%i == 0 || n%(i+2) == 0)
			return false;
	}
	return true;
}

inline bool isEven(lli x){
	if(x&1) {
		return false;
	}
	else{
		return true;
	} 
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,z;
	cin>>t;
	while(t--){
		lli k,count=0;
		cin>>n>>k;
		lli arr[n],br[n];
		lli b1[n][k];
		lli b2[n][k];
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		for (int i=0;i<n;i++){
			cin>>x; 
			arr[i] = x;
			for (int j=0;j<x;j++){
				cin>>y;
				b1[i][y-1] = 1;
			}
			z = 0;
			for (int j=0;j<k;j++){
				if (b1[i][j] != 1){
					b2[i][z++] = j+1;
				}
			}
			br[i] = z;
		}

		for (int i=0;i<n;i++){
			if (br[i] == 0){
				count += n-i-1;
			}
			else{
				for (int j=i+1;j<n;j++){
					f = 0;
					for (int m=0;m<br[i];m++){
						if (b1[j][b2[i][m]-1] != 1){
							f = 1;
							break;
						}
					}
					if (f == 0){
						count++;
					}

				}
			}
		}
		cout<<count<<endl;
	}
	bye;
}
