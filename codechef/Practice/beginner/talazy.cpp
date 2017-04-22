#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	lli n,b,m,k;
	cin>>k;
	while(k--){
		ulli t = 0,z;
		cin>>n>>b>>m;
		while(n != 0){
			if(n%2 == 0){
				z  = n - n/2; 
			}	
			else{
				z = (n+1)/2;
			}
			if(n == 1){
				t += z*m;
			}
			else{
				t += z*m + b;				
			}
			m = 2*m;
			n = n - z;
		}
		cout<<t<<endl;
	}
	return 0;
}
