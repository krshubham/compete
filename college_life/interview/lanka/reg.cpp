/*
* @Author: krshubham
* @Date:   2018-03-27 14:22:14
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-27 14:36:02
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	list<string> l;
	string x;
	for (int i = 0; i < n; ++i){
		cin>>x;
		if(find(l.begin(),l.end(),x) == l.end()){
			l.push_back(x);
		}
	}
	list<string>::iterator it = l.begin();
	for (; it != l.end(); it++){
		cout<<*it<<endl;
	}
	return 0;
}
