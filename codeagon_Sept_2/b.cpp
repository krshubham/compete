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
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828
#define stp(a,b) a.push(b)
#define all(a) a.begin(),a.end()
#define PI 3.1415926535897932384626433832795

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

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
	string x,str;
	vector<char>v1;
	char b,m;
	cin>>x;
	int k,len,a,c,d;
	cin>>k;
	len = x.size();
	int arr[26];
	int res[26];
	for (int i=0;i<26;i++){
		arr[i] = 0;
		res[i] = 0;        
	}
	for (int i=0;i<len;i++){
		b = x[i];
		a = int(b)-97;
		arr[a]++;
	}

	for (int i=0;i<26;i++){
		if (arr[i] >= k){			
			res[i] = 1;
		}   
	}
	for (int i=0;i<len;i++){
		m = x[i];
		d = int(m)-97;
		if (res[d] == 1)
			cout<<m;


	}
	cout<<endl;

}