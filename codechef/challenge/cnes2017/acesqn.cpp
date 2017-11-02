#include<bits/stdc++.h>
using namespace std;

#define MAX 100002

int prime[MAX], countdiv[MAX];

void SieveOfEratosthenes(){
	for (int i = 2; i * i < MAX; ++i){
		if (!prime[i]){
			for (int j = i * i; j < MAX; j += i){
				prime[j] = i;
			}
		}
	}
	for (int i = 1; i < MAX; ++i){
		if (!prime[i]){
			prime[i] = i;
		}
	}
}

int main(){
	int a,b,c,d,t,n;
	cin>>t;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	SieveOfEratosthenes();
	int ans = 1;
	for (int i=0; i < n; ++i){
		int element = arr[i];
		while (element > 1){
			int div = prime[element];
			++countdiv[div];
			ans = max(ans, countdiv[div]);
			while (element % div == 0){
				element /= div;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}