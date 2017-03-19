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
		lli m,n,a;
		cin>>m>>n;
		lli c = 0;
		lli arr[10001],k=0;
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				cin>>a;
				if(a){
					if(arr[j] == 1){
						c++;
					}
					else{
						arr[j] = 1;
					}
				}
			}
		}
		cout<<c*(c-1)/2<<endl;
	}
	return 0;
}
