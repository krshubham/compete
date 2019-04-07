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
	while(t--){
		cin>>a>>b;
		if(b == 1){
			cout<<a<<" ";
			for (int i = 0; i < a; ++i){
				cout<<'a';
			}
			cout<<endl;
			continue;
		}
		if(b != 2){
			cout<<1<<" ";
			c=0;
			while(1){
				x = 97;
				for (int i = 0; i < b; ++i){
					c++;
					cout<<(char)(x+i);
					if(c == a)
						goto end;
				}
			}
			end: 
			cout<<endl;
		}
		else{
			if(a == 1){
				cout<<1<<" "<<'a'<<endl;
				continue;
			}
			else if(a == 2){
				cout<<1<<" "<<"ab"<<endl;
				continue;
			}
			else if(a == 3){
				cout<<2<<" "<<"aab"<<endl;
				continue;
			}
			else if(a == 4){
				cout<<2<<" "<<"aabb"<<endl;
			}
			else if(a == 5){
				cout<<3<<" aaabb"<<endl;
			}
			else if(a == 6){
				cout<<3<<" "<<"aaabbb"<<endl;
			}
			else if(a == 7){
				cout<<"3 aaababb"<<endl;
			}
			else if(a == 8){
				cout<<"3 aaababbb"<<endl;
			}
			else{
				cout<<4<<" ";
				x = ceil((long double)a/3.0);
				string s = "";
				for (int i = 0; i < x; ++i){
					if(i&1){
						s+="bba";
					}
					else s+="aba";
				}
				for (int i = 0; i < a; ++i){
					cout<<s[i];
				}
				cout<<endl;
			}
		}

	}
	bye;
}