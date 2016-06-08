#include <iostream>
using namespace std;

long long int fact(long long int );

int main(int argc, char const *argv[])
{
	long long int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cout<<fact(a)<<endl;
	}
	return 0;
}

long long int fact(long long int n){
	return (n==0 || n==1)?1:n*fact(n-1);
}
