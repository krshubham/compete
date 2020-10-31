#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int temp = 0;
    int count = 1;
    while(true) {
        while(n > 10) {
            temp += ((n%10)<<1);
            n /= 10;
        }
        if(temp == 1) {
            cout<<count<<endl;
            return 0;
        }
        n = temp;
        count++;
    }
    return 0;
}