#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,n,a,p,c=1;
	cin>>t;
	while(t--){
		cin>>n;
		lli arr[n];
		for (int i = 0; i < n; ++i){
			cin>>arr[i];
		}
		for (int i = 1; i < n; ++i){
			if(arr[i] < arr[i-1]){
				c++;
			}
			else{
				arr[i] = arr[i-1];
			}
		}
		cout<<c<<endl;
		c = 1;
	}
	return 0;
}
