#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli arr[n];
		memset( arr, 0, n*sizeof(lli) );
		for (int i = 0; i < n; ++i){
			if(arr[0] == 0){
				cin>>arr[i];
			}
			else{
				cin>>arr[i];
				// get the least possible value of lcm
			}
		}
		for (int i = 0; i < n; ++i){
			cout<<arr[i]<<endl;
		}
	}	
	return 0;
}
