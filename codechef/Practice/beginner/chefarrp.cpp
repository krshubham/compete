#include <iostream>
using namespace std;

#define end return 0

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	lli t,a,b,c,e,d,s,p;
	cin>>t;
	while(t--){
		c = 0;
		cin>>a;
		lli arr[a];
		for (int i = 0; i < a; ++i){
			cin>>arr[i];
		}
		s = 0,p=1;
		for (int i = 0; i < a; ++i){
			s = 0,
			p = 1;
			for (int j = i; j < a; ++j){
				s += arr[j];
				p *= arr[j];
				if(s==p) c++;
			}
		}
		cout<<c<<endl;
	}
	end;
}
