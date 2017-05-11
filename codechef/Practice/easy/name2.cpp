#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,j,xs,m;
	string s,x;
	cin>>t;
	while(t--){
		cin>>s>>x;
		m = s.size();
		xs = x.size();
		j = 0;
		for (int i = 0; i < xs && j<m; ++i){
			if(x[i] == s[j]) j++;
		}
		if(j == m) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
