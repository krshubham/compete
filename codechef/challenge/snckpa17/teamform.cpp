#include <iostream>
using namespace std;

#define end return 0

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,a,b,c,d,e;
	cin>>t;
	while(t--){
		cin>>a>>b;
		for (int i = 0; i < b; ++i){
			cin>>c>>d;
		}
		a -= 2*b;
		if(a%2 == 0){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	end;
}