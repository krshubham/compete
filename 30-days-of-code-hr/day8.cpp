#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	lli t,nu;
	string s;
	map<string,lli> m;
	cin>>t;
	cin.ignore()
	while(t--){
		cin>>s>>nu;
		m[s] = nu;
	}
	while(cin>>s){
		if(m.find(s) == m.end()){
			cout<<"Not found"<<endl;
		}
		else{
			cout<<s<<"="<<m[s]<<endl;
		}
	}
	return 0;
}
