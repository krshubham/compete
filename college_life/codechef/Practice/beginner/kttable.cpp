#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,n,m,k,ov;
	cin>>t;
	while(t--){
		cin>>n;
		lli c = 0;
		lli arr[n],br[n];
		for (int i = 0; i < n; ++i){
			cin>>m;
			if(i == 0){
				arr[i] = m;
			}
			else{
				arr[i] = m - ov;
			}
			ov = m;
		}
		for (int i = 0; i < n; ++i){
			cin>>k;
			if(k<=arr[i]) c++;
		}
		cout<<c<<endl;
	}
	return 0;
}
