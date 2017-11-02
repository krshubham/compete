#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int> &v, int x){
	int carry = 0, res;
	int size = v.size();
	for (int i = 0 ; i < size ; i++){
		int res = carry + v[i] * x;
		cout<<"DEBUG: "<<res;
		v[i] = res % 10;
		carry = res / 10;
	}
	while (carry != 0){
		v.push_back(carry % 10);
		carry /= 10;
	}
}

void print(vector<int> v){
	for (int i = 0; i < v.size(); ++i){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void findSumOfDigits(int n){
	vector<int> v;
	v.push_back(1);

	for (int i=1; i<=n; i++){
		multiply(v, i);
	}

	// int sum = 0;
	// int size = v.size();
	// for (int i = 0 ; i < size ; i++)
	// 	sum += v[i];
	// return 0;
}

int main(){
	for(int i = 1; i<=5; i++){
		findSumOfDigits(i);
	}
	return 0;
}