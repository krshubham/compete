#include <iostream>
using namespace std;

typedef long long ll;
typedef long long lli;
typedef unsigned long long ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	lli t;
	cin>>t;
	while(t--){
		lli cost = 0,nz = 0;
		lli n;
		cin>>n;
		lli arr[n];
		for (int i = 0; i < n; ++i){
			cin>>arr[i];
		}
		for (int i = 0; i < n; ++i){
			if(arr[i] == 0){
				cost += 1100;
				nz++;
			}
			else{
				if(nz>0){
					cost += 100;
				}
			}
		}
		cout<<cost<<endl;
	}	
	return 0;
}