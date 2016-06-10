#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	string a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			if(!(a[i]==b[i] || (a[i]=='?'&&b[i]!='?') || (a[i]!='?'&&b[i]=='?'))){
				cout<<"No"<<endl;
				return 0;
			}
		}
		cout<<"Yes"<<endl;
	}
	return 0;
}
