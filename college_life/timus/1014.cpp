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
#define fi first
#define se second

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

const int PC = 4;
int main(int argc, char const *argv[])
{
	int N;
	int primes[PC] = { 2, 3, 5, 7 };
	cin >> N;
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (N == 0) {
		cout << 10 << endl;
		return 0;
	}

	int a[PC];
	memset(a, 0, sizeof(a));

	int i = 0;
	while (i < PC) {
		if (N % primes[i] == 0) {
			a[i]++;
			N /= primes[i];
		} else i++;
	}
	if (N > 1) {
		cout << -1;
	} 
	else {
		vector<short int> ans; 
		while (a[0] > 2) {
			ans.push_back(8);
			a[0] -= 3;
		}
		while (a[1] > 1) {
			ans.push_back(9);
			a[1] -= 2;
		}
		while (a[0] > 0 && a[1] > 0) {
			ans.push_back(6);
			a[0] -= 1;
			a[1] -= 1;
		}
		while (a[0] > 1) {
			ans.push_back(4);
			a[0] -= 2;
		}
		for (int i = 0; i < PC; i++)
			for (int j = 0; j < a[i]; j++)
				ans.push_back(primes[i]);
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++) cout << ans[i];
		}
	cout << endl;
	return 0;
}