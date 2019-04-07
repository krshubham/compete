#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    int dp[n+2][n+2];
    dp[0][0] = arr[0][0];
    for (int i = 1; i <= n; i++){
        dp[i][0] = dp[i-1][0] + arr[i][0];
    }

    for (int j = 1; j <= n; j++){
        dp[0][j] = dp[0][j-1] + arr[0][j];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + arr[i][j];
        }
    }
    cout<<dp[n][n]<<endl;
    return 0;
}