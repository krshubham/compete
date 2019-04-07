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

inline string solve(vector<lli> s){
	/*
	we have three cases.
	Case1: Input can be all 9's
	*/
	bool nine = true;
	rep(i,s.size()){
		if(s[i] != 9){
			nine = false;
			break;
		}
	}
	string ans = "";
	if(nine == true){
		//all the characters were 9.
		ans += '1';
		rep(i,s.size()-1){
			ans += '0';
		}
		ans += '1';
		return ans;
	}
	/*
	Case 2: 
	When the input number if not palindrome
	Case 3: When the input number is a palindrome
	*/
	lli n = s.size();
	lli mid = n/2;
	bool leftsmaller = false;
	lli i = mid - 1;
	lli j = (n % 2)? mid + 1 : mid;
	while (i >= 0 && s[i] == s[j]){
		i--,j++;
	}

	if ( i < 0 || s[i] < s[j])
		leftsmaller = true;
	while (i >= 0){
		s[j] = s[i];
		j++;
		i--;
	}

	if (leftsmaller == true){
		lli carry = 1;
		i = mid - 1;

		if (n%2 == 1){
			s[mid] += carry;
			carry = s[mid] / 10;
			s[mid] %= 10;
			j = mid + 1;
		}
		else
			j = mid;

		while (i >= 0){
			s[i] += carry;
			carry = s[i] / 10;
			s[i] %= 10;
			s[j++] = s[i--];
		}
	}
	for(lli x: s){
		ans += to_string(x);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	string s;
	cin>>s;
	vector<lli> v;
	rep(i,s.size()){
		v.pb(s[i]-'0');
	}
	cout<<solve(v);
	bye;
}

