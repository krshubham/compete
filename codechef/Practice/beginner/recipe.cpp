#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t;
	int pna,gcd;
	cin>>t;
	while(t--){
		lli a;
		cin>>a;
		int arr[a];
		int min=1001;
		for (int i = 0; i < a; ++i){
			cin>>arr[i];
			if(arr[i] < min){
				min = arr[i];
			}
		}
		for (int i = min; i >=1 ; i--){
			int count = 0;
			for (int j = 0; j < a; ++j){
				if(arr[j]%i == 0){
					count++;
					if(count == a){
						gcd = i;
						goto END;
					}
				}
				else{
					break;
				}
			}
		}
		END: if(gcd == 1){
			for (int i = 0; i < a; ++i){
				cout<<arr[i]<<" ";
			}
		}
		else{
			for (int i = 0; i < a; ++i){
				cout<<arr[i]/gcd<<" ";
			}
		}
	}	
	return 0;
}
