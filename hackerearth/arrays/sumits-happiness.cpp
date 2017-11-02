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
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a[n];
		ll sum=0,flag=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]<=0)
				sum+=a[i];
			if(a[i]>0)
				flag=1;
		}
		if(flag==0){
			cout<<sum<<endl;
		}
		else{
			sort(a,a+n);
			ll sum1=0,f=0,ans,k=0;
			int i;
			for(i=n-1;i>=0&&f==0;i--){
				if(a[i]>=0){
					sum1+=a[i];
					k++;
				}
				else{
					f=1;
				}
			}
			ans=sum1*(k)+sum;
			if(f==1){
				i+=1;
				for(int j=i;j>=0;j--){
					sum1+=a[j];
					sum-=a[j];
					k++;
					ll tmp=(sum1*k)+sum;
					ans=max(ans,tmp);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}  