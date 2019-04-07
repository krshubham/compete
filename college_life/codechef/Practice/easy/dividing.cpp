#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,a=0,s;
	cin>>t;
	for (int i = 0; i < t; ++i){
		cin>>s;		
		a+=s;
	}
	if(a == t*(t+1)/2){
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;
	return 0;
}
