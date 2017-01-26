#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]){
	std:ios_base::sync_with_stdio(false);
	int t;
	string a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		bool f = false;
		for(int i=0;i<a.size();i++){
			if(a[i]==b[i]){
				f = true;
				continue;
			}
			else if((a[i] == '?' && b[i] != '?') || (a[i] != '?' && b[i] == '?')){
				f = true;
				continue;
			}
			else if(a[i] != b[i]){
				f = false;
				cout<<"No"<<endl;
				break;
			}
		}
		if (f)
		{
			cout<<"Yes"<<endl;
		}
	}
	return 0;

}
