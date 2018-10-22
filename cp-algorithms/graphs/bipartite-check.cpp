#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

int color[MAXN];
bool visited[MAXN];

bool dfs(int start, vector<vector<int>>& graph){
    for(auto x: graph[start]){
        if(color[x] == color[start]){
            return false;
        }
        if(!visited[x]){
            visited[x] = 1;
            color[x] = !color[start];
            if(!dfs(x,graph)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    int i = 0;
    while(t--){
        ++i;
        cout<<"Scenario #"<<i<<":"<<endl; 
        int n,m;
        cin>>n>>m; // No of vertices and edges
        int x,y;
        fill(color,color+MAXN, -1);
        fill(visited,visited+MAXN, false);
        vector<vector<int>> graph(n+2);
        for(int i = 0; i < m; i++){
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        bool fl = false;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                visited[i] = 1;
                color[i] = 1;
                if(!dfs(i,graph)){
                    cout<<"Suspicious bugs found!"<<endl;
                    fl = true;
                    break;
                }
            }
        }
        if(!fl){
            cout<<"No suspicious bugs found!"<<endl;
        }
    }
    return 0;
}