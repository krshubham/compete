#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		lli arr[n][m];
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin>>arr[i][j];
			}
		}
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				// if(arr[j][i] == 1){

				// }
				cout<<arr[i][j]<<endl;
			}
		}
	}
	return 0;
}
