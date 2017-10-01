// #include <iostream>
// #include <cstring>
// #include <string>
// #include <cstdio>
// #include <vector>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <cmath>
// #include <utility>
// #include <list>
// #include <iomanip>
// #include <stack>
// #include <climits>
// #include <queue>
#include <bits/stdc++.h>//doesn't work in mac
using namespace std ;

#define bye return 0
#define pb push_back
#define mp make_pair
#define e_val 2.718281828
#define stp(a,b) a.push(b)
#define all(a) a.begin(),a.end()
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
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

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		string s;
		// mlli m;
		// cin>>s;
		// for (int i = 0; i < s.size(); ++i){
		// 	m[s[i]-'0']++;
		// }
		// lli present[26];
		// fill(present, present+26,0);
		// for (int i = 65; i < 90; ++i){
		// 	a = i%10;
		// 	b = i/10;
		// 	if(a != b){
		// 		if( m[a] > 0 && m[b] > 0 ) present[i-65] = 1;
		// 	}
		// 	else{
		// 		if( m[b] >= 2 ) present[i-65] = 1;
		// 	}
		// }
		// string ans = "";
		// for (int i = 0; i < 26; ++i){
		// 	if(present[i] == 1){
		// 		ans += ('A'+ i);
		// 	}
		// }
		// cout<<ans<<endl;
		cin>>s;
		lli arr[10];
		fill(arr,arr+10,0);
		for (int i = 0; i < s.size(); ++i){
			arr[s[i]-'0']++;
		}
		lli present[26];
		fill(present,present+26,0);
		crep(j,65,90){
			lli h,l;
			l = j%10;
			h = j/10;
			if( h != l ){
				if( arr[h] > 0 && arr[l] > 0 ) present[j-65] = 1;
			}
			else{
				if( arr[h] >= 2 ) present[j-65] = 1;
			}
		}
		string ans = "";
		rep(j,26){
			if( present[j] == 1 ) ans += 'A' + j;
		}

		cout<<ans<< endl;
	}
	bye;
}

