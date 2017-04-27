#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t;
	cin>>t;
	while(t--){
		lli a,b;
		cin>>a>>b;
		lli count = 1;
		while(1){
			a -= count;
			count++;
			b -= count;
			count++;
			if(a < 0){
				cout<<"Bob"<<endl;
				break;
			}
			else if(b < 0){
				cout<<"Limak"<<endl;
				break;
			}
		}
	}
	return 0;
}
