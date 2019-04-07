#include <iostream>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,m,n,flag=0,sum=0;
	cin>>t;
	while(t--){
		lli j = 0;
		cin>>m>>n;
		lli arr[m];
		for (int i = 0; i < m; ++i){
			lli a;
			cin>>a;
			if(a <= n){
				arr[j] = a;
				sum += arr[j];
				if(sum == n || arr[j] == n){
					flag = 1;
				}
				j++;
			}
		}
		sort(arr,arr+j+1);
		sum = 0;
		for (int i = j-1; i>=0; i--){
			if(n == 0){
				flag = 1;
			}
			else{
				if(arr[i] <= n - sum){
					
				}
			}
		}
		if(flag == 1){
			cout<<"Yes"<<endl;
			flag = 0;
			sum=0;
		}
		else{

		}
		sum = 0;

	}
	return 0;
}
