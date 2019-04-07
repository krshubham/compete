#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int c = 0;//assuming we will be given positive integers only
	for (int i = 0; i < n; ++i){
		scanf("%d",a+i);
		c = max(c,a[i]);
	}
	printf("%d\n", c);
	return 0;
}