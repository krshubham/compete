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

int main(void){
	map< string, pair<string,int> > users;
	int n;
	string command,p1,p2;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>command;
		
		
		if(command=="register"){
			cin>>p1>>p2;
			if(users.empty() || users.find(p1)==users.end()){
				users[p1]=make_pair(p2,0);
				cout<<"success: new user added"<<endl;
			}
			else cout<<"fail: user already exists"<<endl;
		}
		
		
		if(command=="login"){
			cin>>p1>>p2;
			if(users.find(p1)!=users.end()){
				if(users[p1].first==p2){
					if(users[p1].second==0){
						users[p1].second=1;
						cout<<"success: user logged in"<<endl;
					}
					else cout<<"fail: already logged in"<<endl;
				}
				else cout<<"fail: incorrect password"<<endl;
			}
			else cout<<"fail: no such user"<<endl;
		}
		
		
		if(command=="logout"){
			cin>>p1;
			if(users.find(p1)!=users.end()){
				if(users[p1].second==1){
					users[p1].second=0;
					cout<<"success: user logged out"<<endl;
				}
				else cout<<"fail: already logged out"<<endl;
			}
			else cout<<"fail: no such user"<<endl;
		}
	}
	
	return 0;
}
