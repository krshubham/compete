/*
* @Author: krshubham
* @Date:   2018-03-25 12:22:32
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-25 12:24:40
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int a,b,c;
	cin>>a>>b>>c;
	int d = b*b - 4*a*c;
	if(d > 0){
		cout<<"REAL AND DISTINCT"<<endl;
	}
	else if(d == 0){
		cout<<"REAL AND EQUAL"<<endl;
	}
	else{
		cout<<"UNREAL"<<endl;
	}
	return 0;
}
