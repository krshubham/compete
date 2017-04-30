#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	ulli t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(b==0){
			cout<<0<<" "<<a<<endl;
		}
		else{
			cout<<a/b<<" "<<a%b<<endl;

		}
	}
	return 0;
}
