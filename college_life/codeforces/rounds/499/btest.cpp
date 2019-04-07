#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,n,m;
int a[1000],c[1000];
int b[1000];
int main(){
cin>>n>>m;
if (m<n) {
    cout<<0<<endl;
    exit(0);
    }
for(i=1; i<=m; i++) {cin>>l; a[l]++;}
for(i=1; i<=m; i++){b[i]=a[i];}
sort(b+1,b+m+1); 
l=0;
for(i=1; i<=100; i++){ 
    k = 0;
    for(j=100; j>=1; j--){
        if (b[j]/i>0) {
            k=k+b[j]/i;
        }
    }
    if (k>=n) l=max(i,l);
}
cout<<l<<endl;
return 0;
}