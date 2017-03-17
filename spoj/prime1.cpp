#include <iostream>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef double dbl;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	lli t;
	cin>>t;
	while(t--){
		ulli m,n;
		cin>>m>>n;
		for (int i = m; i <= n; ++i){
			if((i!=2 && i!=3 && i!=5 && i!=7 && i!=11) && (i%2==0 || i%3==0 || i%5 != 0 && i%5 != 0 )){

			}
		}
	}	
	return 0;
}
