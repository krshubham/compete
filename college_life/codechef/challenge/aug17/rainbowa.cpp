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
	while(t--){
		cin>>n;
		lli a[8],arr[n],flag = 0;
		fill(a,a+8,0);
		for (int i = 0; i < n; ++i){
			cin>>arr[i];
			if(arr[i] == 0 || arr[i] > 7){
				flag = 1;
			}
			else a[arr[i]]++;
		}
		for (int i = 1; i < 8; ++i){
			if(a[i] == 0){
				flag = 1;
				break;
			}
		}
		if(flag) cout<<"no"<<endl;
		else{
			for(int i=0;i<n/2;i++){
				if(arr[i] == arr[n - i - 1] && a[arr[i]-1]==0){
					a[arr[i]]-=2;
				}
				else{
					flag = 1;
					break;
				}
			}
			if(flag)
				cout<<"no"<<endl;
			else
				cout<<"yes"<<endl;
		}
	}
	bye;
}

