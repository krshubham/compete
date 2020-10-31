#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    long n;
    while(t--) {
        cin>>n;
        long result = 0;
        long prod = 5;
        while(prod <= n) {
            result += n/prod;
            prod *= 5;
        }
        cout<<result<<endl;
    }
    return 0;
}