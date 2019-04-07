#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a>b){
			cout<<">"<<endl;
		}
		else if(a<b){
			cout<<"<"<<endl;
		}
		else{
			cout<<"="<<endl;
		}
	}
	return 0;
}
