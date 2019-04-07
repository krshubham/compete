#include <stdio.h>


int main(){
    int a, b,c,x;
    scanf("%d %d %d", &a, &b, &c);
    int cnt[100];
    for(int i = 0; i < 100; i++){
        cnt[i] = 0;
    }
    for(int i = 0; i < a+b+c; i++){
        scanf("%d",&x);
        cnt[x]++;
    }
    int ans[100];
    int k = 0;
    for(int i = 0; i < 100; i++){
        if(cnt[i] >= 2){
            ans[k++] = i;
        }
    }
    printf("%d\n",k);
    for(int i = 0; i < k; i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}