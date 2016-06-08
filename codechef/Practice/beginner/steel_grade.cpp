#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t,a,b,c;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		if(a>50 && b<0.7 && c>5600){
			cout<<"10"<<endl;
		}
		else if(a>50 && b<0.7){
			cout<<"9"<<endl;
		}
		else if(b<0.7 && c>5600){
			cout<<"8"<<endl;
		}
		else if(a>50 && c>5600){
			cout<<"7"<<endl;
		}
		else if(a>50 || b<0.7 || c>5600)
	}
	return 0;
}
