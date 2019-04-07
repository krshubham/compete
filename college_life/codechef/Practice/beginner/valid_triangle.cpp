
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,a,b,c;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b>>c;
		if(a+b+c==180 && a!=0 && b!=0 && c!=0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}