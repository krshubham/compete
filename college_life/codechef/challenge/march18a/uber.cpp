/*
* @Author: krshubham
* @Date:   2018-03-17 21:38:17
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-17 21:40:14
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,c;
	cin>>n;
	int arr[n];
	c = 1;
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
		c *= arr[i];
	}
	for (int i = 0; i < n; ++i){
		cout<<c/arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
