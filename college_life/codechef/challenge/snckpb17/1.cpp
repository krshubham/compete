#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(){
	ios_base::sync_with_stdio(0);
	string arr;
	lli t,n,s,m;
	cin>>t;
	while(t--){
		cin>>arr;
		n = arr.size();
		char x = arr[0];
		lli s=0,m=0;
		for (int i = 0; i < n; ++i){
			if(arr[i] == 'm') m++;
			else s++;
		}
		for (int i = 0; i < n; ++i){
			if(arr[i] == 'm'){
				if(i==0){
					if(arr[i+1] == 's') s--;
				}
				else if(i==n-1){
					if(arr[i-1] == 's') s--;
				}
				else{
					if(arr[i-1] == 's' || arr[i+1] == 's') s--;
				}
			}
		}
		if(s>m)
			cout<<"snakes"<<endl;
		else if(s<m)
			cout<<"mongooses"<<endl;
		else
			cout<<"tie"<<endl;
	}
	return 0;
}