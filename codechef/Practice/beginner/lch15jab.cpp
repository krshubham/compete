#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		string a;
		int max = 0;
		cin>>a;
		vector<char> v;
		for (int i = 0; i < a.length(); ++i)
		{
			if(find(v.begin(),v.end(),a[i]) == v.end()){
				v.push_back(a[i]);
			}
		}
		for (int i = 0; i < v.size(); ++i)
		{
			 if(count(a.begin(),a.end(),v[i])>max){
			 	max = count(a.begin(), a.end(),v[i]);
			 }
		}
		if(max == a.length()/2 && a.length()%2 == 0){
			cout<<"YES"<<"\n";
		}
		else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}
