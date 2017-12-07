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
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )
#define endl '\n'
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef unsigned long long ull;
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
int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	string s;
	while(cin>>s){
		lli i,j,k,l,m,g1=0,g2=0;
		string a,b;
		for(i=0;i<20;i+=2){
			a=a+s[i];
		}
		for(i=1;i<20;i+=2){
			b=b+s[i];
		}  
		lli f=0;
		for(i=0,j=0;i<5;){ 
			if((g1>g2+5-j)||(g2>g1+5-i)){
				f=1;
				break;
			}
			if(a[i++]=='1'){ 
				g1++;
			}
			if((g1>g2+5-j)||(g2>g1+5-i)){
				f=1;
				break;
			}

			if(b[j++]=='1'){
				g2++;
			}
			if((g1>g2+5-j)||(g2>g1+5-i)){
				f=1;

				break;
			}
		}

		if(f==1 && g1!=g2){
			if(g1>g2){
				cout<<"TEAM-A "<<i+j<<endl;
			}
			else{
				cout<<"TEAM-B "<<i+j<<endl;
			}
		}
		else{
			for(i=5;i<10;i++){
				if(a[i]=='1'&&b[i]=='0'){
					cout<<"TEAM-A "<<2*i+2<<endl;
					break;
				}
				if(a[i]=='0'&&b[i]=='1'){
					cout<<"TEAM-B "<<2*i+2<<endl;
					break;
				}   
			}
			if(i==10){
				cout<<"TIE"<<endl;
			}
		}
	}

}