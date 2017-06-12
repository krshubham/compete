#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for (int i = 0; i < 2*n; ++i){
			if(i%2 != 0){
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
