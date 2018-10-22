#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(!(n&(n-1))&& n){
        cout<<"Not possible"<<endl;
    }
    else{
        cout<<"Possible"<<endl;
    }
    return 0;
}