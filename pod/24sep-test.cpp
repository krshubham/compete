#include <bits/stdc++.h>
using namespace std;

int main(){
    string sa,sb;
    cin>>sa>>sb;
    int j = 0;
    for(int i = 0; i < sa.size() && j < sb.size(); i++){
        if(sa[i] == sb[j]){
            j++;
        }
    }
    cout<<(j == sb.size() ? "Yes" : "No")<<endl;
    return 0;
}