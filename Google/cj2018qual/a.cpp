/*
* @Author: krshubham
* @Date:   2018-04-07 13:50:19
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-04-07 14:56:12
*/
#pragma comment (linker, "/stack:20000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
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
#define endl '\n'

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef unsigned long long ull;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef unordered_map<lli,lli> umlli;
typedef vector<pair<lli,lli> > vplli;

inline vector<string> split(string str,string sep){char* cstr=const_cast<char*>(str.c_str());char* current;vector<string> arr;current=strtok(cstr,sep.c_str());while(current!=NULL){arr.push_back(current);current=strtok(NULL,sep.c_str());}return arr;}
inline bool isPrime(lli n){if (n <= 1){return false;}if (n <= 3)  {return true;}if (n%2 == 0 || n%3 == 0) {return false;}for (int i=5; i*i<=n; i=i+6){if (n%i == 0 || n%(i+2) == 0){return false;}}return true;}
inline lli power(lli x,lli y,lli p){int res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y = y>>1;x = (x*x) % p;}return res;}

bool cmp(const char a, const char b){
	return a > b;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	string s;
	for (int i = 1; i <= t; ++i){
		a = 0;
		cin>>d>>s;
		bool fl = false;
		c = 0;
		x = 1<<0;
		for (int j = 0; j < s.size(); ++j){
			if(s[j] == 'S'){
				fl = true;
				c += x;
			}
			else{
				x <<= 1;
			}
		}
		if(!fl){
			cout<<"Case #"<<i<<": "<<0<<endl;
			continue;
		}
		string test = s;
		sort(all(test),cmp);
		// cout<<s<<" "<<test<<endl;
		if(d >= c){
			cout<<"Case #"<<i<<": "<<0<<endl;
			continue;
		}
		else{
			bool fl = false;
			while(s != test){
				for (int j = s.size()-1; j > 0; j--){
					if(s[j] == 'S' && s[j-1] == 'C'){
						a++;
						swap(s[j],s[j-1]);
						break;
					}
				}
				c = 0;
				x = 1;
				for (int j = 0; j < s.size(); ++j){
					if(s[j] == 'S'){
						c += x;
					}
					else{
						x <<= 1;
					}
				}
				if(c <= d){
					// cout<<"The final string is:"<<" "<<s<<endl;
					cout<<"Case #"<<i<<": "<<a<<endl;
					fl = true;
					break;
				}
			}
			if(!fl)
			cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
		}
	}
	bye;
}

