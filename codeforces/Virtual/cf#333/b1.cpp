#include <bits/stdc++.h>
using namespace std;
#define N 110000
int f[N],g[N],h[N];
int main(){
    int a[110000];
    int v=0;
    int n;
    cin>>n ;
    for(int i=0;i<n;i++){
        cin>>a[i] ;
    }
    for(int i=n-1;i>=0;--i){
        if(i==n-1){
            f[i]=g[i]=h[i]=0;
        }
        else if(a[i]==a[i+1]){
            f[i]=1+f[i+1];
            g[i]=g[i+1];
            h[i]=h[i+1];
        }
        else if(a[i]==a[i+1]-1){
            f[i]=0;
            g[i]=h[i+1]+f[i+1]+1;
            h[i]=0;
        }
        else if(a[i]==a[i+1]+1){
            f[i]=0;
            h[i]=1+f[i+1]+g[i+1];
            g[i]=0;
        }
        else{
            f[i]=0;
            h[i]=0;
            g[i]=0;
        }
    }
    for(int j=0;j<n;j++)
        v=max(v,1+f[j]+g[j]+h[j]) ;
    cout<<v<<endl;
}