#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	set<char>  myset;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0; i<s.length(); i++){
		s.at(i) = tolower(s.at(i));
		myset.insert(s.at(i));
	}
	if(myset.size()==26) cout<< "YES"<<endl;
	else cout<< "NO"<<endl;
}