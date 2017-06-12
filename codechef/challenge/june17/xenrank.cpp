#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,a,b,c,d,x,y;
	cin>>t;
	while(t--){
		cin>>a>>b;
		a++;
		c = (a + (a * a)) / 2 + (((2 * a) + b - 1) * b) / 2;
		cout<<c<<endl;
	}
	return 0;
}
