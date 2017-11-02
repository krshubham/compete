#include <iostream>
using namespace std;

typedef long long int lli;

int main(){
	ios_base::sync_with_stdio(0);
	lli a,b,c,d,e,f,g,h;
	cin>>a>>b>>c>>d>>e;
	lli days = 0;
	while(a != 0){
		a -= b;
		if(a <= 0){
			++days;
			cout<<days<<endl;
			return 0;
		}
		b+=d;
		if(b >= c){
			b = c;
		}
		a += e;	
		++days;
	}
	cout<<days<<endl;
	return 0;
}