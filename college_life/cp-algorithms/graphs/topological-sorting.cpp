#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

bool visited[MAXN];

void dfs(int start, vector<vector<int>>& graph, vector<int>& ans){
    visited[start] = true;
    for(auto x:graph[start]){
        if(!visited[x]){
            dfs(x,graph,ans);
        }
    }
    ans.push_back(start);
}



int main(){
    fill(visited,visited+MAXN,false);
    int n,m,x,y;
    cin>>n>>m;//nodes and edges
    vector<vector<int>> graph(n+2);
    for(int i = 0; i < m; i++){
        cin>>x>>y;
        graph[x].push_back(y);
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i,graph,ans);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto node:ans){
        cout<<node<<" ";
    }
    cout<<endl;
    return 0;
}