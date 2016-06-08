#include <iostream>
#include <cstdlib>
using namespace std;

void isprime(int n){
	for(int i=2;i<=n/2;i++){
		if(n%i==0)
			{cout<<"no"<<endl;
		return;}	
	}
	cout<<"yes"<<endl;
}

int main(int argc, char const *argv[])
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		isprime(n);
	}
	return 0;
}