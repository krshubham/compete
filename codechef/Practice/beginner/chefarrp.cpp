#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	lli t;
	cin>>t;
	while(t--){
		lli a;
		cin>>a;
		lli arr[a];
		for (int i = 0; i < a; ++i){
			cin>>arr[i];
		}
		lli cs=0,cp;
		for (int i = 0; i <=a; ++i){
			for (int j = i; j < a; ++j){
				cp = i*j;
				cs = i+j;
			}
		}
	}
	return 0;
}
