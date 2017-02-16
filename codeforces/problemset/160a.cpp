#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	lli t;
	cin>>t;
	lli arr[t],sum=0,num=0;
	for (int i = 0; i < t; ++i){
		cin>>arr[i];
		sum += arr[i];
	}
	sort(arr, arr+t, std::greater<int>());
	for (int i = 0; i < t; ++i){
		
	}
	return 0;
}
