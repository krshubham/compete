#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,n,x,sum=0,a;
	cin>>t;
	while(t--){
		cin>>n>>x;
		for (int i = 0; i < n; ++i){
			cin>>a;
			sum+=a;
		}
		if(sum/x < n){
			cout<<-1<<endl;
		}
		else
			cout<<sum/x<<endl;
		sum = 0;
	}
	return 0;
}
