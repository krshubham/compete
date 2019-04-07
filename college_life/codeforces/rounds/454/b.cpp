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

int main(){
	ios_base::sync_with_stdio(0);
	vector<vector <char> > v(9, vector<char>(9));
	for(int i=0;i<9;i++)
		for (int j = 0; j < 9; j++){
			char tmp;
			cin >> tmp;
			if(tmp!=' ')
			v[i][j] = tmp;
		}
	int x, y;
	cin >> x >> y;
	x %= 3; y %= 3;
	if (x == 0)
		x = 3;
	if (y == 0)
		y = 3;
	bool check = false;
	for (int i = (x - 1) * 3; i <= x * 3 - 1; i++)
		for (int j = (y - 1) * 3; j <= y * 3 - 1; j++)
			if (v[i][j] == '.')
				check = true;
	if (check){
		for (int i = (x - 1) * 3; i <= x * 3 - 1; i++)
			for (int j = (y - 1) * 3; j <= y * 3 - 1; j++)
				if (v[i][j] == '.')
					v[i][j] = '!';
	}
	else
		for (int i = 0; i <9; i++)
			for (int j = 0; j <= 9; j++)
				if (v[i][j] == '.')
					v[i][j] = '!';
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << v[i][j];
		}
		cout<<" ";
		for (int j = 3; j < 6; j++){
			cout << v[i][j];
		}
		cout<<" ";
		for (int j = 6; j < 9; j++){
			cout << v[i][j];
		}
		cout << endl;
	}
	cout<<endl;
	for (int i = 3; i < 6; i++){
		for (int j = 0; j < 3; j++){
			cout << v[i][j];
		}
		cout<<" ";
		for (int j = 3; j < 6; j++){
			cout << v[i][j];
		}
		cout<<" ";
		for (int j = 6; j < 9; j++){
			cout << v[i][j];
		}
		cout << endl;
	}
	cout<<endl;
	for (int i = 6; i < 9; i++){
		for (int j = 0; j < 3; j++){
			cout << v[i][j];
		}
		cout<<" ";
		for (int j = 3; j < 6; j++){
			cout << v[i][j];
		}
		cout<<" ";
		for (int j = 6; j < 9; j++){
			cout << v[i][j];
		}
		cout << endl;
	}
	bye;
}

