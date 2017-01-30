#include <iostream>
#include <stdbool.h>
using namespace std;



typedef long long ll;
typedef long long int lli;



int main(int argc, char const *argv[]){
	ll t;
	cin>>t;
	while(t--){
		lli a;
		ll b;
		cin>>a>>b;
		lli count = 0;
		while(a != b){
			if(a%2 != 0){
				if(a == 1){
					a = a<<1;
					count++;
				}
				else{
					a = (a-1)/2;
					count++;
				}
			}
			else{
				if(a > b){
					a = a>>1;
					count++;
				}
				else{
					a = a<<1;
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}	