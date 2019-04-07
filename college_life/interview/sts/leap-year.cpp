/*
* @Author: krshubham
* @Date:   2018-03-25 12:14:58
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-25 12:20:07
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int n;
	cin>>n;
	if(n%400 == 0){
		cout<<"Yes"<<endl;
	}
	else{
		if(n%4 == 0){
			if(n%100 == 0){
				cout<<"No"<<endl;
			}
			else{
				cout<<"Yes"<<endl;
			}
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
