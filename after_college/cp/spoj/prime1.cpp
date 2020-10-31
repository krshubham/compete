#include <bits/stdc++.h>
using namespace std;

inline long isPrime(long n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n%i == 0) return false;
    }
    return true;
}


int main() {
    int t;
    cin>>t;
    int l,r;
    while(t--) {
        cin>>l>>r;
        for(long i = max(2,l); i <=r; i++) {
            if(isPrime(i)) {
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}