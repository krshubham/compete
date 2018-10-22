#include <bits/stdc++.h>
using namespace std;

inline bool count_vowels(string& s, int k){
    int cnt = 0;
    for(auto c:s){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            cnt++;
        }
    }
    return (cnt == k);
}

int main(){
    string word;
    int k;
    cin>>word;
    cin>>k;
    vector<string> substrings;
    int n = word.size();
    for(int i = 0; i < word.size(); i++){
        for(int j = 0; j <= n-i; j++){
            substrings.push_back(word.substr(i,j));
        }
    }
    int cnt = 0;
    for(auto x:substrings){
        cout<<x<<endl;
        if(count_vowels(x,k)){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}