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

string changeStr(string str){
	string s = str;
	bool done = false;
	lli j = 0;
	while(done != true){
		for (int i = 0; i < s.size()-1; ++i){
			if(s[i] == 'k' && s[i+1] == 'h'){
				s[i] = 'h';
				s[i+1] = (char)NULL;
				done = false;
				break;
			}
			else{
				done = true;
			}
		}
	}
	return s;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	string s;
	set<string> se;
	rep(i,n){
		cin>>s;
		while(s.find("u")!=string::npos)s=s.replace(s.find('u'),1,"oo");
		while(s.find("kh")!=string::npos)s=s.replace(s.find("kh"),2,"h");
		se.insert(s);
	}
	cout<<se.size()<<endl;
	bye;
}

