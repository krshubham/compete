#include <bits/stdc++.h>
using namespace std;

inline int reverse_number(int n) {
    if(n == 0) return 0;
    int result = 0;
    int multiplier = 1;
    while(n != 0) {
        result = result*10 + n%10;
        n /= 10;
    }
    return result;
}


int main() {
    int t;
    cin>>t;
    int x,y;
    while(t--) {
        cin>>x>>y;
        cout<<reverse_number(reverse_number(x) + reverse_number(y))<<endl;
    }
    return 0;
}