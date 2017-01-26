#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		ll n,m,k,diff;
		cin>>n>>m>>k;
		diff = abs(n-m);
		if(diff == k || diff<k){
			cout<<0<<endl;
		}
		else{
			cout<<diff-k<<endl;
		}
	}
	return 0;
}
