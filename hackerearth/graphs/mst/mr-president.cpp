#include <bits/stdc++.h>
using namespace std;
#define faster cin.tie(0);ios_base::sync_with_stdio(0)
#define testcase int tc;cin>>tc;while(tc--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define REP0(i,a,b) for(int i=a;i<b;i++)
#define REPA(i,a,b,c) for(int i=a;i<b;i+=c)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
#define MAX 1000001
ll mod=1000000007;

int nodes,edges;

ll i,weight,k;
vl id(MAX);

void init(){
    for(i=0;i<MAX;i++)id[i]=i;
}

ll root(ll x){
    while(x!=id[x]){
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void uni(ll x,ll y){
    ll p=root(x);
    ll q=root(y);
    id[p]=id[q];
}
ll ans(pair<ll,pair<int,int> > p[]){
    ll minC=0,x,y,w,ctr=0;
    vector<ll> wt;
    for(i=0;i<edges;i++){
        w=p[i].first;
        x=p[i].second.first;
        y=p[i].second.second;
        if(root(x)!=root(y)){
            minC+=w;
            wt.push_back(w);
            uni(x,y);
        }
    }
    int ind=wt.size()-1;
    while(minC>k&&ind>=0){
        minC=minC-wt[ind]+1;
        ind--;
        ctr++;
    }
    if(minC>k){
        return -1;
    }
    return ctr;
}
bool DFS(vector<int> adj[]){
    vector<bool> visited(nodes+1, false);
    visited[0]=true;
    stack<int> st;
    st.push(1);
    while(!st.empty()){
        int t=st.top();
        st.pop();
        if(visited[t]==false){
        visited[t]=true;
    }
    for (auto it = adj[t].begin(); it != adj[t].end(); ++it)
        if (!visited[*it])
            st.push(*it);
        }
    for(int i=1;i<=nodes;i++) if(visited[i]==false) return false;
    return true;
}

pair<ll,pair<int,int> > p[MAX];
int main() {
    init();
    faster;
    int x,y;
    cin>>nodes>>edges>>k;
    vector<int> adj[nodes+1];
    for(i=0;i<edges;i++){
        cin>>x>>y>>weight;
        adj[x].push_back(y);
        adj[y].push_back(x);
        p[i]=make_pair(weight,make_pair(x,y));
    }
    sort(p,p+edges);
    if(!DFS(adj))cout<<"-1"<<endl;
    else cout<<ans(p)<<endl;
    return 0;
}