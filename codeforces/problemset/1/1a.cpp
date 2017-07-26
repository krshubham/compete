#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli n,m,a,c=0,d=0,f=0;
	cin>>n>>m>>a;
	if(n==m){ 
		f=1;
	}
	if(a == 1){
		c = n,d=m;
		cout<<c*d<<endl;
		return 0;
	}
	while(!(n <= 0)){
		n = n - a;
		c++;
	}
	if(f == 1){
		cout<<c*c<<endl;
		f = 0;
		return 0;
	}
	while(!(m <= 0)){
		m = m-a;
		d++;
	}
	cout<<c*d<<endl;

	return 0;
}
