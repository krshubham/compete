#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(){
	ios_base::sync_with_stdio(0);
	lli t,a,b,sum=0,j,prime=0;
	cin>>t;
	while(t--){
		cin>>a>>b;
		j = 1;
		if(a+b == 2){
			cout<<1<<endl;
		}
		else{
			while(prime == 0){
				for (int i = 2; i <= sqrt(a+b+j); ++i){
					if((a+b+j) % i == 0){
						j++;
						prime = 0;
						break;
					}
					else{
						prime = 1;
					}
				}
			}
			cout<<j<<endl;
			prime = 0;
			j = 1;
		}
	}
}