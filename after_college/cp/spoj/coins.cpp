#include <bits/stdc++.h>
using namespace std;

unordered_map<long,long> dp;

long solve(long n) {
    if(n == 0 || n == 1) {
        return n;
    }
    if(dp.find(n) == dp.end()) {
        return dp[n] = max(n,solve(n/2) + solve(n/3) + solve(n/4));
    }
    else return dp[n];
}



int main() {
    long n;
    while(cin>>n) {
        cout<<solve(n)<<endl;
    }
    return 0;
}