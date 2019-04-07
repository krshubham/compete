#include <iostream>
using namespace std;

#define end return 0

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b;
	cin>>t;
	while(t--){
		cin>>n;
		for (int i = 0; i < 2*n; ++i){
			cin>>a;
		}
		b = 1;
		if(n == 1){
			cout<<b<<endl;
		}
		else{
			for (int i = 2; i <= n; ++i){
				b ^= i;
			}
			cout<<b<<endl;
		}
	}
	/** A good joke Mr. setter XD **/
	end;
}