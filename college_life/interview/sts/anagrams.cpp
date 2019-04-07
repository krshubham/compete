/*
* @Author: krshubham
* @Date:   2018-03-25 10:55:52
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-25 11:02:02
*/
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]){
	string sa,sb;
	cin>>sa>>sb;
	transform(sa.begin(),sa.end(),sa.begin(),::tolower);
	transform(sb.begin(),sb.end(),sb.begin(),::tolower);
	unordered_map<char,int> m1,m2;
	for(auto c:sa){
		m1[c]++;
	}
	for(auto c:sb){
		m2[c]++;
	}
	if(m1.size() != m2.size()){
		cout<<"Not Anagrams"<<endl;
	}
	else{
		bool fl = false;
		for(auto it = m1.begin(); it != m1.end(); it++){
			if(m2[it->first] != it->second){
				cout<<"Not Anagrams"<<endl;
				fl = true;
			}
		}
		if(!fl){
			cout<<"Anagrams"<<endl;
		}
	}
	return 0;
}
