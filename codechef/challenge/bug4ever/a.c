#include <stdio.h>


typedef long long int lli;

int main(int argc, char const *argv[]){
	int a,b,c,d,e,f,n,m,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d:%d %d:%d %d:%d",&a,&b,&c,&d,&e,&f); 
		n = ((a*60+b) - (e*60+f)) + (c*60+d)-(a*60+b);
		if(n > 59){
			printf("59\n");
		}
		else printf("%d\n",n);
	}
	return 0;
}