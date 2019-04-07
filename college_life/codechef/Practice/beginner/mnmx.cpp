#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	int t;
	cin>>t;
	while(t--){
		lli n,min=100000001;
		cin>>n;
		for (int i = 0; i < n; ++i){
			lli a;
			cin>>a;
			if(a < min){
				min = a;
			}	
		}
		cout<<min*(n-1)<<endl;
	}	
	return 0;
}

