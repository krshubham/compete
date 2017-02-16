#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

int main(int argc, char const *argv[]){
	int t;
	scanf("%d",&t);
	while(t--){
		char *str;
		long long int n,m;
		scanf("%s %lli %lli",str,n,m);
		char *temp = str;
		while(--n){	
			strcat(str,temp);
		}
		printf("%s\n",str);
	}
	return 0;
}