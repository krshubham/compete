#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    int a;
    getline(cin,s);
    cin>>a;
    set<char> st;
    for(auto x:s){
        if(x != ' '){
            st.insert(x);
        }
    }
    int i = 0;
    string _ans;
    for(auto& c:st){
        cout<<c<<endl;
        _ans.push_back(c);
        if(_ans.size() > a){
            _ans.pop_back();
            break;
        }
    }
    cout<<_ans<<endl;
}