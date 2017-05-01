#include <iostream>
#include <map>
using namespace std;


typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,q;
	string s;
	map<string, lli> m;
	cin>>t;
	while(t--){
		cin>>s;
		m[s]++;
	}
	cin>>q;
	for (int i = 0; i < q; ++i){
		cin>>s;
		cout<<m[s]<<endl;
	}
	return 0;
}
