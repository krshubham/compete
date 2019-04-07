#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e;
	cin>>t>>n;
	lli arr[t];
	lli min = 999999;
	for (int i = 0; i < t; ++i){
		cin>>a;
		arr[i] = abs(a-n);
	}
	for (int i = 0; i < t; ++i){
		cin>>b;
		arr[i] /= b;
		if(arr[i] < min){
			min = arr[i];
			c = i;
		}
	}
	sort(arr,arr+t);
	if(arr[0] == arr[1]){
		cout<<-1<<endl;
	}
	else{
		cout<<c<<endl;
	}
	return 0;
}
