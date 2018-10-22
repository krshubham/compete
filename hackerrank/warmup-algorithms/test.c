#include <stdio.h>

void incrementPatternPrint(int N, int s){
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            printf("%d",s);
        }
        printf("\n");
        s++;
    }
    s--;
    for(int i = N; i > 0; i--){
        for(int j = 0; j < i; j++){
            printf("%d",s);
        }
        printf("\n");
        s--;
    }
}

int main(){
    incrementPatternPrint(4,3);
    return 0;
}