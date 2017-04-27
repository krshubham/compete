#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,a,b,p;
	cin>>t;
	while(t--){
		cin>>a;
		lli arr[a];
		for (int i = 0; i < a; ++i){
			cin>>arr[i];
		}
		for (int i = 0; i < a; ++i){
			for (int j = i ; j < a; ++j){
				cout<<"i = "<<i<<" j = "<<j<<endl;	
			}
		}
	}
	return 0;
}
