#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	ulli t,n,sum = 0;
	double a,k,up,down;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 0; i < n; ++i){
			cin>>a;
			up = k*(ceil(a/k));
			down = k*(floor(a/k));
			if(down == 0){
				sum += up - a;
			}
			else if((up - a) > (a - down)){
				sum += a - down;
			}
			else{
				sum += up - a;
			}
		}
		cout<<sum<<endl;
		sum = 0;
	}
	return 0;
}
