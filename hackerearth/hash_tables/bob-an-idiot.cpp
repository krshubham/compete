#include<iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <utility>

#define ft first
#define sd second
using namespace std;
map<char,int> M1;
map<char,char> M2;
int main(){
	int n;
	cin>>n;
	char ch1,ch2,ch;
	for(int i=0;i<26;i++)
	M1['A'+i]=i;
	for(int i=0;i<n;i++){
		cin>>ch1>>ch2;
	}
	for(map<char,int> :: iterator it=M1.begin();it!=M1.end();++it)
	{
		M2[it->sd+'A']=it->ft;
		M2[it->sd+'a']=it->ft+32;
	}
	string str="";
	while(cin>>ch&&ch!=EOF){
		str+=ch;
	}
	n=str.length();
	for(int i=0;i<n;i++){
		if(M2[str[i]])
		cout<<M2[str[i]];
		else
		cout<<str[i];
	}
	cout<<endl;
	return 0;
}