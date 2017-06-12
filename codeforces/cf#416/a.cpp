#include <iostream>
using namespace std;

#define end return 0

typedef long long ll;
typedef long long int lli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli a,b,c,d,e,f;
	cin>>a>>b;
	c = 1;
	d = 1;
	while(1){
		if(c%2 != 0){
			a-= d;
		}
		else{
			b -= d;
		}
		d++;
		c++;
		if(a < 0){
			cout<<"Vladik"<<endl;
			end;
		}
		else if(b<0){
			cout<<"Valera"<<endl;
			end;
		}
	}
	return 0;
}
