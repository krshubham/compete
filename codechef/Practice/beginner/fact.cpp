#include <iostream>
using namespace std;

int fact(int );

int main(int argc, char const *argv[])
{
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cout<<fact(a)<<endl;
	}
	return 0;
}

int fact(int n){
	return (n==0 || n==1)?1:n*fact(n-1);
}
