#include <stdio.h>

int __gcd(int a, int b){
    if (b == 0) {
        return a; 
    }
    return __gcd(b, a % b);
}

int main(){
    int n;
    scanf("%d",&n);
    int x;
    int g;
    for(int i = 0; i < n; i++){
        scanf("%d",&x);
        if(i == 0){
            g = x;
        }
        else{
            g = __gcd(g,x);
        }
    }
    if(g == 1){
        printf("NO");
    }
    else{
        printf("YES");
    }
    return 0;
}