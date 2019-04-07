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
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )
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

//without set
int main(){
	ios_base::sync_with_stdio(0);
	lli n;
	cin >> n;
	vector<string> a(n);
	vector<char> op(n);
	for(int i = 0; i < n; i++){
		cin >> op[i] >> a[i];
	}
	vector<int> b(26, 1);
	int count = 0;
	bool end = 0;
	for(int i = 0; i < n; i++){
		if(op[i] == '.'){
			for(char c: a[i]){
				b[c - 'a'] = -1;
			}
		}
		if(op[i] == '!'){
			count += end;
			for(int j = 0; j < 26; j++){
				bool f = false;
				for(int k = 0; k < a[i].size(); k++){
					if(a[i][k] - 'a' == j){
						f = true;
					}
				}
				if(!f){
					b[j] = -1;
				}
			}
		}
		if(op[i] == '?')
			if(i != n - 1){
				count += end;
				b[a[i][0] - 'a'] = -1;
			}
			int x = 0, y = 0;
			for(int j = 0; j < 26; j++)
				if(b[j] == 1){
					x++;
				}
				else if(b[j] == -1){
					y++;
				}
				if(x == 1 && y == 25){
					end = 1;
				}
			}
			cout<<count<<endl;
			bye;
		}

