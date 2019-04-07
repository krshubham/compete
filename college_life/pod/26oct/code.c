#include <stdio.h>
#define mod(n) (n) % 1000000007


const int MAXN = 1e3;

int main(){
    int a,b;
    int dp[MAXN];
    for(int i = 0; i < MAXN; i++){
        dp[i] = 0;
    }
    scanf("%d %d",&a,&b);
    dp[0] = a;
    dp[1] = b;
    for(int i = 2; i < MAXN; i++){
        dp[i] = mod(mod(3*dp[i-1]) + mod(4*dp[i-2]));
        dp[i] = mod(dp[i]);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%d ",dp[x-1]);
    }
    printf("\n");
    return 0;   
}