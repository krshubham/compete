#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define end return 0

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int maxSubarrayXOR(int arr[], int n){
    int ans = INT_MIN;

    for (int i=0; i<n; i++){
        int curr_xor = 0;

        for (int j=i; j<n; j++){
        	
        	curr_xor = curr_xor ^ arr[j];
        	ans = max(ans, curr_xor);
        	
        }
    }
    return ans;
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	int n,m,o,p,t;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}
	end;
}
