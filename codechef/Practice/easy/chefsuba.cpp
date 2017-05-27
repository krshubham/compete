#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

void build(lli t[],lli n){
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

int query(int l, int r,lli n, lli t[]) {
  cout<<l<<" "<<r<<endl;  
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
}
return res;
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);
    lli n,k,p;
    cin>>n>>k>>p;
    lli t[2*n],r[2*n];
    for (int i = 0; i < n; ++i) scanf("%lld", t + n + i);
        build(t,n);
    for (int i = 0,j=i+k-1; j < n; ++i,j++){
        cout<<query(i,j+1,n,t)<<endl;
    }
    return 0;
}