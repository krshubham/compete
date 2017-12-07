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
	string s;
	while(t--){
		cin>>s;
		lli ans[2]={0,0};
		x = 0,y=0;
		lli i = 0;
		char ch;
		if(s[0]=='A') ch='A';
		else if(s[0]=='B') ch='B';
		else ch='.';
		c=0;
		while(i < s.size()){
			if(s[i]=='.'){
				c+=1;
			}
			else if(s[i]==ch){
				ans[ch-'A']+=c+1;
				c=0;
			}
			else if(s[i]!=ch){
				c=0;
				ch=s[i];
				ans[ch-'A']+=1;
			}
			i++;
		}
		cout<<ans[0]<<" "<<ans[1]<<endl;
	}
	bye;
}

