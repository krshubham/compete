#include <stdio.h>
#define mod(n) (n) % 1000000007
const int MAXN = 1e3+5;

int main(){
    int dp[MAXN];
    int q;
    scanf("%d",&q);
    int x;
    while(q--){
        scanf("%d",&x);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i < MAXN; i++){
            dp[i] = mod(mod(dp[i-1]) + mod(dp[i-2]));
        }
        printf("%d\n",dp[x+1]);
    }
    return 0;
}