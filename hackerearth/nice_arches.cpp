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
	string s;
	stack<char> st;
	cin>>t;
	c = t;
	for (int i = 0; i < t; ++i){
		cin>>s;
		a = s.size();
		if(!isEven(a)){
			c--;
			continue;
		}
		st.push(s[0]);
		for (int j = 1; j < a; ++j){
			if(st.empty()) st.push(s[j]);
			else{
				if(st.top() == s[j]) {
					st.pop();
				}
				else {
					st.push(s[j]);
				}				
			}
		}
		if(!st.empty()) c--;
		while(!st.empty()){
			st.pop();
		}
	}

	cout<<c<<endl;
	bye;
}

