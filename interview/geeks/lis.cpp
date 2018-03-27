/*
	author: krshubham
	12.03.2018, 20:09 IST
*/

#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]){
	int t;
	cin>>t;
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}
	int ans = 0;
	for (int i = 1; i < n; ++i){
		if(arr[i] > max_so_far){
			ans++;
		}
	}
	return 0;
}
