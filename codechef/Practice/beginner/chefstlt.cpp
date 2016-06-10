#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	int min=0,max=0;
	string a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			if(a[i]!= b[i] && (a[i]!='?' && b[i]!='?' )){
				min++;
			}
			else if((a[i]==b[i] && (a[i]=='?' && b[i]=='?')) || (a[i]!=b[i] && (a[i]=='?' || b[i]=='?'))){
				max++;
			}
		}
		max = min + max;
		cout<<min<<" "<<max<<endl;
		min=max=0;
	}
	return 0;
}
