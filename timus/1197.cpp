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
	cin>>n;
	lli board[8][8];
	char ca;
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			if(i == 0 || i == 7){
				if(j == 0 || j == 7)
					board[i][j] = 2;
				else if(j == 1 || j == 6)
					board[i][j] = 3;
				else
					board[i][j] = 4;
			}
			else if(i == 1 || i == 6){
				if(j == 0 || j == 7){
					board[i][j] = 3;
				}
				else if(j == 1 || j == 6)
					board[i][j] = 4;
				else 
					board[i][j] = 6;
			}
			else{
				if(j == 0 || j == 7){
					board[i][j] = 4;
				}
				else if(j == 1 || j == 6){
					board[i][j] = 6;
				}
				else{
					board[i][j] = 8;
				}
			}
		}
	}
	rep(i,n){
		cin>>ca>>a;	
		cout<<board[ca-'a'][--a]<<endl;
	}
	bye;
}

