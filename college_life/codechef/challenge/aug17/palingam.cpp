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
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	string sa,sb;
	while(t--){
		cin>>sa>>sb;
		char ans = 'B';		
		lli arr[26] = {0};
		lli brr[26] = {0};
		lli len = sa.size();
		for (int i = 0; i < len; ++i){
			arr[sa[i] - 'a']++;
			brr[sb[i] - 'a']++;
		}
		int flag1=1,flag2=0,flag3=0;
		for(int i=0;i<26;i++) {
			if(brr[i]!=0&&arr[i]==0)
				flag1=0;
			if(arr[i]!=0&&brr[i]==0)
				flag2=1;
			if(arr[i]>=2&&brr[i]==0)
				flag3=1;
		}
		if(flag1 == 1&&flag2 == 1)
			ans='A';
		if(flag3 == 1)
			ans='A';
		cout<<ans<<endl;
	}
	bye;
}

