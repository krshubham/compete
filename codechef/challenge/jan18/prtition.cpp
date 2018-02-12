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
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		cin>>x>>n;
		ll arr[n];
		fill(arr,arr+n,0);
		ll c = n*(n+1)/2-x;
		if (c%2==1){
			cout<<"impossible"<<endl;
			continue;
		}
		c = c/2;
		arr[x-1] = 2;
		ll k = n,t = 0,fc = c;
		while(c!=0){
			if (arr[k-1]==2){
				k--;
				continue;
			}
			if (c-k>=0){
				c -= k;
				arr[k-1] = 1;
				k--;
			}
			else{
				if (arr[c-1]==2){
					t = 1;
					break;
				}
				else{
					arr[c-1] = 1;
					c = 0;	
				}
				
				
			}
		}
		if (t == 1){
			fill(arr,arr+n,0);
			c = fc;
			arr[x-1] = 2;
			k = n-1;
			while(c!=0 && k>1){
				if (arr[k-1]==2){
					k--;
					continue;
				}
				if (c-k>=0){
					c -= k;
					arr[k-1] = 1;
					k--;
				}
				else{
					arr[c-1] = 1;
					c = 0;
				}
			}
			
		}
		c = fc;
		lli res1=0,res2=0;
		for (lli i=0;i<n;i++){
			if (arr[i]==0)
				res1 += i+1;
			else if (arr[i]==1)
				res2 += i+1; 
		}
		if (res1!=res2 || res1!=c || res2!=c){
			cout<<"impossible"<<endl;
			continue;
		}
		else{
			string z;
			for (lli i=0;i<n;i++){
				z += (arr[i]+'0');
			}
			cout<<z<<endl;	
		}
		
	}
}