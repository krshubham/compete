#include <bits/stdc++.h>
using namespace std;
#define ll long long

void ppsum() {
    int n, d;
    cin>>d>>n;
    int answer = n;
    for (int i = 1; i <= d; i++) {
        answer = answer*(answer + 1) / 2;
    }
    cout<<answer<<endl;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        ppsum();
    }
    return 0;
}