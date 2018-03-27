/*
* @Author: krshubham
* @Date:   2018-03-25 10:35:05
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-25 10:53:26
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		int c = 0;
		for (int i = 0; i < s.size(); ++i){
			if(s[i] == '9'){
				c++;
				continue;
			}
			else{
				break;
			}
		}
		if(c==s.size()){
			//all 9's
			long long int num = stoll(s);
			cout<<num+2<<endl;
		}
		if(s.size()&1){//odd size string
			bool fl = true;
			//checking if the given number is a palindrome
			for (int i = 0; i < s.size()/2; ++i){
				if(s[i] != s[s.size()-i-1]){
					fl = false;
					break;
				}
			}
			if(fl){
				
			}
		}
	}
	return 0;
}
