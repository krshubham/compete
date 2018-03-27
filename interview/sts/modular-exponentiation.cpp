/*
* @Author: krshubham
* @Date:   2018-03-25 11:02:48
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-25 11:51:51
*/
#include <bits/stdc++.h>
using namespace std;

int power(int x,int y){
	int res = 1;
	while(y > 0){
		if(y&1){
			res = res*x;
		}
		y >>= 1;
		x = x*x;
		cout<<"x = "<<x<<" and res = "<<res<<endl;
	}
	return res;
}

int main(int argc, char const *argv[]){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<power(a,b);
	}
	return 0;
}
	