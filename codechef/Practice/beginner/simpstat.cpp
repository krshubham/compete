#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(){
	lli t,n;
	double k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		double arr[n];
		for(int i=0; i<n;i++){
			cin>>arr[i];
		}
		sort(arr, arr+n);
		lli start = k;
		lli end = n - k - 1, sum = 0;
		for(int i=start; i<=end; i++){
			sum+=arr[i];
		}
		cout<<fixed<<setprecision(6)<<(ll)sum/(n-2*k)<<endl;
	}
	return 0;
}