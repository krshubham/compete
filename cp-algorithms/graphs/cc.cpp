#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;


bool visited[MAXN];
int color[MAXN];

bool dfs(int start, vector<vector<int>>& graph){
    for(auto x:graph[start]){
        if(!visited[x]){
            visited[x] = true;
            color[x] = !color[start];
            if(!dfs(x,graph)){
                return false;
            }
        }
        else if(color[x] == color[start]){
            return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    int x,y;
    vector<vector<int>> graph(n+2);
    for(int i = 0; i < m; i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    fill(visited,visited+MAXN,false);
    fill(color,color+MAXN,-1);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            color[i] = 1;
            if(!dfs(i,graph)){
                cout<<"Not bipartite"<<endl;
                return 0;
            }
        }
    }
    cout<<"bipartite graph"<<endl;
    return 0;
}