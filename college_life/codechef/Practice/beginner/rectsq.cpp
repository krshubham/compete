#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b;
		c = a;
		d = b;
		ll a;
		while(c!=d){
			if(c>d){
				c = c-d;
			}
			else{
				d = d-c;
			}
		}
		cout<<(a*b/(c*c))<<endl;
	}
	return 0;
}
