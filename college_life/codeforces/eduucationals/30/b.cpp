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

void findSubArray(string arr, lli n){
	int maxsize = -1, startindex;  
	int sumleft[n];
	int min, max; 
	int i;
	sumleft[0] = ((arr[0] == '0')? -1: 1);
	min = arr[0];
	max = arr[0];
	for (i=1; i<n; i++){      
		sumleft[i] = sumleft[i-1] + ((arr[i] == '0')? -1: 1);
		if (sumleft[i] < min)
			min = sumleft[i];
		if (sumleft[i] > max)
			max = sumleft[i];
	}
	mlli hash;

	for (i=0; i<max-min+1; i++)
		hash[i] = -1;
	for (i=0; i<n; i++){
		if (sumleft[i] == 0){
			maxsize = i+1;
			startindex = 0;
		}

		if (hash[sumleft[i]-min] == -1)
			hash[sumleft[i]-min] = i;
		else{
			if ((i - hash[sumleft[i]-min]) > maxsize){
				maxsize = i - hash[sumleft[i]-min];
				startindex = hash[sumleft[i]-min] + 1;
			}
		}
	}
	if (maxsize == -1)
		cout<<0<<endl;
	else
		cout<<maxsize<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	string s;
	cin>>s;
	findSubArray(s,n);
	bye;
}

