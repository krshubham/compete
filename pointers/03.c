//copy string without using strcpy.
#include <stdio.h>
#include <stdlib.h>

int main(){
	char strA[80] = "A string to be used for demonstration purposes";
	char strB[80];
	char *pA;
	char *pB;
	pA = strA;
	puts(pA);
	pB = strB;
	putchar('\n');
	while(*pA != '\0'){
		*pB++ = *pA++;//copying the two strings using pointers
	} 
	*pB = '\0';
	puts(strB);
	return 0;
}