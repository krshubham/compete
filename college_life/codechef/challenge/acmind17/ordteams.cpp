#include <bits/stdc++.h>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828
#define stp(a,b) a.push(b)
#define all(a) a.begin(),a.end()
#define PI 3.1415926535897932384626433832795
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )
#define endl '\n'
#define fi first
#define se second

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

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	lli arr[3][3];
	while(t--){
		lli sa = 0,saa=0, sb = 0,sbb=0, sc = 0,scc=0;
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){
				cin>>arr[i][j];
			}
		}
		for (int i = 0; i < 3; ++i){
			if((arr[0][i] >= arr[1][i] ) && arr[0][i] >= arr[2][i]){
				sa++;
			}
			if((arr[0][i] > arr[1][i] ) && arr[0][i] > arr[2][i]){
				saa++;
			}
		}
		for (int i = 0; i < 3; ++i){
			if((arr[1][i] >= arr[0][i] ) && arr[1][i] >= arr[2][i]){
				sb++;
			}
			if((arr[1][i] > arr[0][i] ) && arr[1][i] > arr[2][i]){
				sbb++;
			}
		}
		for (int i = 0; i < 3; ++i){
			if((arr[2][i] >= arr[1][i] ) && arr[2][i] >= arr[0][i]){
				sc++;
			}
			if((arr[2][i] > arr[1][i] ) && arr[2][i] > arr[0][i]){
				scc++;
			}
		}
		if((saa >= 1 && sa == 3) || (sb == 3 && sbb >= 1) || (sc == 3 && scc >= 1)){
			cout<<"yes"<<endl;
		}
		else cout<<"no"<<endl;
	}
	bye;
}