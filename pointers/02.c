//printing the contents of an array using pointers

#include <stdio.h>

int main(){
	int arr[] = {1,23,17,4,-5,100};
	int *ptr;
	ptr = &arr[0];
	int i;
	for(i=0;i<6;i++){
		printf("%d\n",*ptr);
		ptr++;
	}
	return 0;
}