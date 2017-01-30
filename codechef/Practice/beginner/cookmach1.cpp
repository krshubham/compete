#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;

int main(int argc, char const *argv[])
{

	// Srategy is to first make the number a multiple of 2 and then
	// if the number is big or small do accordingly
	lli t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		ll count = 0;
		
		// do this while a is not a multiple of 2;
		while((a & -a) != a){
			a = a>>1;
			count++;
		}
		while(a > b){
			a = a>>1;
			count++;
		}
		while(a < b){
			a = a<<1;
			count++;
		}
		cout<<count<<endl;

	}
	return 0;
}