#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    long long n,k,x,y;
    cin>>t;
    while(t--) {
        cin>>n>>k>>x>>y;
        unordered_set<long long> seen;
        auto current_num = x;
        seen.insert(current_num);
        while(1) {
            if(k == 1) {
                cout<<"YES"<<endl;
                break;
            }
            if(current_num == y) {
                cout<<"YES"<<endl;
                break;
            }
            current_num = (current_num + k) % n;
            if(seen.find(current_num) != seen.end()) {
                cout<<"NO"<<endl;
                break;
            }
            seen.insert(current_num);
        }
    }
}