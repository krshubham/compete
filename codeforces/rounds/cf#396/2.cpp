#include <iostream>
#include <algorithm>
using namespace std;


typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	ulli t;
	cin>>t;
	lli arr[t];
	for (int i = 0; i < t; ++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+t);
	for (int i = 2; i < t; ++i){
		if(arr[i] < arr[i-1] + arr[i-2]){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
