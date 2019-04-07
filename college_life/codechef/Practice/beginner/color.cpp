#include <iostream>
using namespace std;


typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main() {
	lli t,n,rr=0,rg=0,rb=0;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'R') rr++;
			else if(s[i] == 'G') rg++;
			else rb++;
		}
		
	}
	return 0;
}