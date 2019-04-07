/*
* @Author: Kumar Shubham
* @Date:   2018-03-12 20:38:53
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-12 20:55:07
*/
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		string ans="";
		if(n == 1){
			cout<<1<<endl;
			continue;
		}
		for (int i = 9; i >= 2; i--){
			if(n%i == 0){
				while(n%i == 0){
					n /= i;
					ans += to_string(i);
				}
			}
		}
		if(n > 10){
			cout<<-1<<endl;
		}
		else{
			reverse(ans.begin(),ans.end());
			cout<<ans<<endl;
		}
	}
	return 0;
}
