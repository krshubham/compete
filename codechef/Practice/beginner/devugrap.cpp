#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ulli t;
	cin>>t;
	while(t--){
		ulli a,b;
		ulli arr[a];
		for (int i = 0; i < a; ++i){
			cin>>arr[i];
		}
		ulli gcd;
		for (int i = 0; i < a-1; ++i){
			if(__gcd(arr[i],arr[i+1]) == 1){
				gcd = 1;
			}
			else{
				gcd = 
			}
		}
	}
	return 0;
}
