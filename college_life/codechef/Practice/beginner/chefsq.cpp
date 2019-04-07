#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	lli t;
	cin>>t;
	while(t--){
		lli a,b;
		cin>>a;
		lli o[a];
		for (int i = 0; i < a; ++i){
			cin>>o[i];
		}
		cin>>b;
		lli f[b];
		for (int i = 0; i < b; ++i){
			cin>>f[i];	
		}
		int j = 0;
		for (int i=0; i<a&&j<b; i++){
			if (f[j] == o[i])	
				j++;
		}
		cout<<((j==b) ? "Yes" : "No" )<<endl;
	}	
	return 0;
}
