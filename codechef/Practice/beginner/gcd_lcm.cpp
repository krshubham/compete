#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	int t,a,b,i;
	cin>>t;
	while(t--){
		cin>>a>>b;
		for( i=max(a,b);i>=1;i--){
			if(a%i==0 && b%i==0){
				cout<<i<<" ";
				break;
			}
		}
		cout<<(a*b)/i<<endl;
	}
	return 0;
}
//Requires bit manipulation else giving TLE.