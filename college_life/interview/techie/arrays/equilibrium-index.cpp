#include <stdio.h>

int equilibrium(int arr[], int n){
	int sum = 0;
	int leftsum = 0;
	int i;

	for (i = 0; i < n; ++i)
		sum += arr[i];

	for( i = 0; i < n; ++i){
		sum -= arr[i];

		if(leftsum == sum)
			return i;

		leftsum += arr[i];
	}
	return -1;
}

int main(){
	int arr[] = {-7, 1, 5, 2, -4, 3, 0};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	cout<<"First equilibrium index is %d\n"<<equilibrium(arr, arr_size)<<endl;
	return 0;
}