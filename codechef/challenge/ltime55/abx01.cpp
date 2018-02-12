#pragma comment (linker, "/stack:20000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define endl '\n'

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef unsigned long long ull;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef unordered_map<lli,lli> umlli;
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
	ulli t,n,a,b,c,e,f,x,y;
	cin>>n;
	ulli two[] =  {2,4,8,7,5,1};
	ulli four[] =  {4,7,1};
	ulli five[] =  {5,7,8,4,2,1};
	ulli seven[] = {7,4,1};
	while(n--){
		cin>>a;
		a%=9;
		if(a==0)
			a=9;
		cin>>b;
		if(a==1 || a==9){
			cout<<(a)<<endl;
		}
		else if(a==3 || a==6){
			if(b==1)
				cout<<(a)<<endl;
			else
				cout<<(9)<<endl;
		}
		else if(a==8){
			if(b%2==1)
				cout<<(8)<<endl;
			else
				cout<<(1)<<endl;
		}
		else if(a==2){
			lli d=(lli)(b%6)-1;
			if(d==-1)
				d=5;
			cout<<(two[d])<<endl;
		}
		else if(a==4){
			lli d=(lli)(b%3)-1;
			if(d==-1)
				d=2;
			cout<<(four[d])<<endl;
		}
		else if(a==5){
			lli d=(lli)(b%6)-1;
			if(d==-1)
				d=5;
			cout<<(five[d])<<endl;
		}
		else{
			lli d=(lli)(b%3)-1;
			if(d==-1)
				d=2;
			cout<<(seven[d])<<endl;
		}
	}
	bye;
}

