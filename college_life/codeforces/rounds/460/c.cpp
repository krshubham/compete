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

vector<string> split(string str,string sep){
	char* cstr=const_cast<char*>(str.c_str());
	char* current;
	vector<string> arr;
	current=strtok(cstr,sep.c_str());
	while(current!=NULL){
		arr.push_back(current);
		current=strtok(NULL,sep.c_str());
	}
	return arr;
}

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

char arr[2005][2005];

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,m,k;
	cin>>n>>m>>k;
	string s;
	rep(i,n){
		cin>>s;
		rep(j,m){
			arr[i][j] = s[j];
		}
	}
	lli cnt = 0;
	rep(i,n){
		c = 0;
		rep(j,m){
			if(arr[i][j] == '.'){
				c++;
			}
			else{
				if(c >= k){
					cnt += (c-k+1);
					c = 0;
				}
			}
		}
	}
	rep(i,m){
		c = 0;
		rep(j,n){
			if(arr[j][i] == '.'){
				c++;
				if(c == k){
					if(arr[j+1][i] == '.'){
						c = 1;
					}
					else c = 0;
					cnt++;
				}
			}
			else{
				c = 0;
			}
		}
	}
	cout<<cnt<<endl;
	bye;
}