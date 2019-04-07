#include <stdio.h>

int main(){
    unsigned int m,n,t;
	scanf("%d%d",&m,&n);
	for(int i=0;i<32;i++){
		if((m&(1<<i)) == (n&(1<<i))){
		    printf("%d ",i+1);
        }
	}
    return 0;
}