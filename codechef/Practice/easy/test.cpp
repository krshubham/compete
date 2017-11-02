#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s="";
        int k=0;
        char c='a';
        while(k!=n)
        {
            s=c+s;
            if(c!='a')
                k++;
            if(c=='z')
                c='a';
            else
                c++;
        }
        cout<<s<<"\n";
    }
    return 0;
}   