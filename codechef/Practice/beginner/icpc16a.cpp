#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;

int main() {
	lli t,a,b,c,d;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		if(a != c && b != d){
			cout<<"sad"<<endl;
		}
		else if(a == c && b>d){
			cout<<"down"<<endl;
		}
		else if(a==c && b<d){
			cout<<"up"<<endl;
		}
		else if(b==d && a>c){
			cout<<"left"<<endl;
		}
		else if(b ==d && a< c){
			cout<<"right"<<endl;
		}
	}
	return 0;
}