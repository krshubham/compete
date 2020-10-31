#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    for(int i= 0; i <= n; i++){
        cout<<i<<" & "<<i+1<<" = "<<(i&(i+1))<<endl;
    }

    for(int i = 0; i  < n; i++) {
        for(int j = i; j <= n; j++)  {
            cout<<i<<" & "<<j<<" = "<<(i&j)<<endl;
        }
    }
    return 0;
}