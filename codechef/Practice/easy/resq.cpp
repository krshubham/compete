#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int isPrime(lli a){
	for (int i = 2; i < sqrt(a); ++i){
		if(a%i == 0){
			return 0;
		} 
	}
	return 1;
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,a;
	cin>>t;
	while(t--){
		cin>>a;
		if(isPrime(a)){
			cout<<a-1<<endl;
		}
		else{
			
		}
	}	
	return 0;
}
