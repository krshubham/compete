/*
* @Author: krshubham
* @Date:   2018-03-16 21:28:14
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-16 21:39:10
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int n;
	cin>>n;
	int x;
	long long int arr[n];
	for (long long int i = 0; i < n; ++i){
		cin>>x;
		arr[i] = ((x&1) ? 1 : 0);
	}
	unordered_map<long long int,long long int> m;
	long long int c = 0;
	for (long long int i = 0; i < n; ++i){
		c += ((arr[i] == 0) ? -1 : arr[i]);
		m[c]++;
	}
	long long int cnt = 0;
	for (auto it = m.begin(); it != m.end(); it++){
		if(it->second > 1){
			cnt += ((it->second)*(it->second-1))/2;
		}
	}
	if(m.find(0) != m.end()){
		cnt += m[0];
	}
	cout<<cnt<<endl;
	return 0;
}
