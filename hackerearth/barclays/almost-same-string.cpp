#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        string x,y;
        ll arr[26];
        fill(arr,arr+26,0);
        cin>>x>>y;
        ll a = x.size();
        ll b = y.size();

        for (int i=0;i<a;i++){
            arr[x[i]-'a']++;
        }

        for (int i=0;i<b;i++){
            arr[y[i]-'a']++;
        }

        ll ans = INT_MAX;
        ll res = 0;
        ll k,tt;
        cin>>k;
        for (int i=0;i<26;i++){
            res = 0;
            for (int j=i+k+1;j<26;j++){
                tt = min(j,26-j);
                res += abs(j-i-k)*arr[j];
            }
            cout<<"res= "<<res<<endl;
        }
        //cout<<ans<<endl;

    }
}