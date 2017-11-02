#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <iomanip>
#include <stack>
#include <climits>
#include <queue>
#include <string>
#include <cstring>
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
#define first F
#define second S

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

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}

int main(){
	int t;cin>>t;
	while(t--){
		string a,b,ans;
		cin>>a>>b;
		if(a.size()==1 && b.size()==1){
			int d = ((int)(a[0]-'0')+(int)(b[0]-'0'))%10;
			cout<<d<<endl;
			continue;
		}
		if(a.size()<b.size())
		{
			string t = a;
			a=b;
			b=t;
		}
		if(a.size()!=b.size())
			for(int i=0;i<=(a.size()-b.size());i++)
				b='0'+b;
		//cout<<a<<endl;
		//cout<<b<<endl;	
			int fl=0;
			for(int i=0;i<a.size();i++)
			{
				int d = ((int)(a[i]-'0')+(int)(b[i]-'0'))%10;
				if(fl==0 && d==0){
					fl=1;
				}
				else{
					cout<<d;
					fl=1;
				}
			}
			cout<<endl;
		}
		bye;
	}

