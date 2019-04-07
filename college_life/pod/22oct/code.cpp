#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> ones;
    string s;
    for(int i = 0; i < n; i++){
        cin>>s;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '1'){
                // Finding all the position where there is a 1
                ones.push_back({i,j});
            }
        }
    }        
    unordered_map<int,int> distances;
    for(int i = 0; i < ones.size(); i++){
        for(int j = i+1; j < ones.size(); j++){
            // for every manhattan distance checking if the point exists or not
            distances[abs(ones[i].first-ones[j].first)+abs(ones[i].second-ones[j].second)]++;
        }
    }
    int q;
    cin>>q;
    int x;
    while(q--){
        cin>>x;
        // Number of pairs with given distances
        cout<<distances[x]<<endl;
    }
    return 0;
}