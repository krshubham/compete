#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef unsigned long long ull;




int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	int t,n,k,m;
	cin>>t;
	while(t--){
		cin>>n>>k>>m;
		if(n%k == 0){
			cout<<n/k<<" "<<1<<endl;
		}
		else{
			cout<<ceil((double)n/(double)k)<<" "<<endl;
		}
	}
	return 0;
}
