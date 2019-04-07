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

vector<string> tokenize(string s){
	vector<string> v;
	char *newc = new char[s.size() + 1];
	strcpy(newc,s.c_str());
	char *p = strtok(newc," ");
	while(p != 0){
		v.pb(p);
		p = strtok(NULL," ");
	}
	return v;
}

const string specialChars = "[$&+,:;=?@#|'<>.-^*()%!]";

void reverse(vector<string> v){
	for(string i:v){	
		reverse(all(i));
		for (int j = 0; j < specialChars.size(); ++j){
			if(i[0] == specialChars[j]){
				i+=i[0];
				i[0] =  NULL;
			}
		}
		cout<<i<<" ";
	}
	cout<<endl;
}

inline bool isChar(const char& c){
	return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}

int main(){
	string s;
	int len;
	while(getline(cin,s)){
		len=s.length();
		int start=0,end=0;
		while(end<len){
			while(end<len&&isChar(s[end]))end++;

			for(int i=end-1;i>=start;i--)cout<<s[i];
				start=end;
			while(start<len&&!isChar(s[start])){
				cout<<s[start];
				start++;
			}
			end=start;
		}
		cout<<endl;
	}
	return 0;
}

