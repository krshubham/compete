#include <stdio.h>

int j,k;
int *ptr;

int main(){
	j = 1;
	k = 2;
	ptr = &k;
	printf("j has the value %d and is stored at %p\n",j,(void *)&j);
	printf("k has the value %d and is stored at %p\n",k,(void *)&k);
	printf("ptr has the value %p and is stored at %p\n",ptr,(void *)&ptr);
	printf("ptr points to the value %d\n",*ptr);	
}