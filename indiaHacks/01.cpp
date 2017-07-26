#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
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
	if (n <= 1)  return false;
	if (n <= 3)  return true;

	if (n%2 == 0 || n%3 == 0) return false;

	for (int i=5; i*i<=n; i=i+6)
		if (n%i == 0 || n%(i+2) == 0)
			return false;

		return true;
	}

	inline bool isEven(lli x){
		if(x&1) return false;
		else return true;
	}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a=0,b,c,d,e,f,x,y;
	cin>>n;
	lli arr[n];
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}
	lli max1 = 0,count=0,si,li,old;
	for (int i = 0; i < n; ++i){
		if(arr[i] == 1){
			if(a == 0){
				x = i;
				a = 1;
			}
			count++;
		}
		else{
			a = 0;
			y = i-1;
			old = max1;
			max1 = max(count,max1);
			if(old != max1){
				si = x;li = y;
			}
			count = 0;
		}
	}
	cout<<max1<<"\t"<<si<<"\t"<<li<<endl;
	count = 0,max1 = 0;
	for (int i = 0; i < n; ++i){
		cout<<arr[i]<<" ";
		if(arr[i] == 1){
			count++;
		}
		else{
			max1 = max(count,max1);
			count = 0;
		}
	}
	cout<<max1<<endl;
	bye;
}
