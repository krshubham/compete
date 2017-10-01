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
#include <unordered_set>
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

void print(string start, map<string, string> m, string end){
	// if(m[start] == "") {
	// 	cout<<endl;
	// 	return;	
	// }
	// cout<<start<<"-"<<m[start]<<" ";
	// print(m[start], m,m[m[start]]);
	while(m[start] != ""){
		cout<<start<<"-"<<m[start]<<" ";
		start = m[start];
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		cin>>n;
		map<string,lli> m;
		map<string,string> ma;
		string s,ss;
		set<pair<string,string> > v;
		rep(i,n){
			cin>>s>>ss;
			m[s]++;
			m[ss]++;
			v.insert(mp(s,ss));
			ma[s] = ss;
		}
		string end,start;
		vector<string> ans;
		set<pair<string,string> >::iterator it;
		for (it = v.begin(); it!= v.end(); it++){
			if(m[it->first] == 1){
				start = it->first;
				break;
				//this is done using vim
			
			}
		}
		print(start,ma,ma[start]);
	}
	bye;
}

