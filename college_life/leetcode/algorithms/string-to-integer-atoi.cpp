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

// int myAtoi(string str) {
// 	int j = 0;
// 	while(str[j] == ' '){
// 		j++;
// 	}
// 	double x;
// 	int nf=0;
// 	if(str[j] == '-'){
// 		nf = 1;
// 		j++;
// 	}
// 	else if(str[j] == '+'){
// 		j++;
// 	}
// 	for (int i = j; i < str.size(); ++i){
// 		if(str[i] >= '0' && str[i] <= '9'){
// 			x = x*10 + str[i]-'0';
// 		}
// 	}
// 	if(nf == 1){
// 		x = -x;
// 	}
// 	if(x > INT_MAX){
// 		return INT_MAX;
// 	}
// 	else if(x < INT_MIN){
// 		return INT_MIN;
// 	}
// 	return x;
// }

int myAtoi(string str) {
	if(str.size() == 0){
		return 0;
	}
	int j = 0;
	while(str[j] == ' '){
		j++;
	}
	int nf = 0;
	if(str[j] == '-'){
		nf = 1;
		j++;
	}
	else if(str[j] == '+'){
		j++;
	}
	double x = 0;
	for (int i = j; i < str.size() && (str[i] >= '0' && str[i] <= '9'); ++i){
		x = x*10 + str[i]-'0';
	}
	if(nf == 1){
		x = -x;
	}
	if(x > INT_MAX){
		return INT_MAX;
	}
	else if(x < INT_MIN){
		return INT_MIN;
	}
	return (int)x;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	string s;
	getline(cin,s);
	cout<<myAtoi(s)<<endl;
	bye;
}

