/**
* @author: krshubham
* @time: 16:34:23
**/
#include <stdio.h>


int main(){
    int t,n,a,b,c,d,e,f,x,y,s;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d", &n, &x, &s);
        c = x;
        for(int i = 0; i < s; i++){
            scanf("%d %d", &a, &b);
            if(a == c){
                c = b;
            }
            else if(b == c){
                c = a;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}