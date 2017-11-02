#include<bits/stdc++.h>
using namespace std;
int main(){
    set<string> s;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string k;cin>>k;
        while(k.find("u")!=string::npos)k=k.replace(k.find("u"),1,"oo");
        while(k.find("kh")!=string::npos)k=k.replace(k.find("kh"),2,"h");
        s.insert(k);
    }
    cout<<s.size()<<endl;
}