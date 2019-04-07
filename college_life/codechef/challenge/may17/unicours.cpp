#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main() {
    lli t,n;    
    cin >> t;
    while(t--){
        cin>>n;
        lli a[n];

        for(int i = 0; i < n; i++) {
            cin>>a[i];
        }
        
        lli r = 1,q = 0;

        for(int i = n-1; i > q + 1; i--){
            if (a[i] < i) r++;
            if(q < a[i] - 1){
                q = a[i] - 1;
            }
        }
        cout<<r<<endl;
    }
    return 0;
}