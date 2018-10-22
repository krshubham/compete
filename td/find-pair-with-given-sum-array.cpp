#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    int x;
    cin>>x;
    unordered_map<int,int> ma;
    for(int i = 0; i < n; i++){
        if(ma.find(x-v[i]) != ma.end()){
            cout<<v[ma[x-v[i]]]<<" "<<v[i]<<endl;
            return 0;
        }
        ma[v[i]] = i;
    }
    cout<<"There is no pair with given sum"<<endl;
    return 0;
}