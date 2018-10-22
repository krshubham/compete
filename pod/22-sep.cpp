#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

inline bool isPrime(int x){
    if(x <= 1) return false;
    if (x <= 3) return true;

    if(x%2 == 0 || x%3 == 0){
        return false;
    }

    for(int i = 5; i*i <= x; i += 6){
        if(x%i == 0 || (x%(i+2)) == 0){
            return false;
        }
    }
    return true;
}

vector<bool> visited(MAXN,false);
vector<int> res(MAXN,0);
int query(int node, vector<int> tree[], vector<int>& tokens){
    int count = 0;
    for(int child:tree[node]){
        if(isPrime(tokens[child])){
            count++;
        }
        count += query(child,tree,tokens);
    }
    return count;
}

int main(){
    int n; 
    cin>>n;
    vector<int> tokens(n);
    for(int i = 0; i < n; i++){
        cin>>tokens[i];
    }
    vector<int> tree[n+1];
    int x,y;
    for(int i = 0; i < n-1; i++){
        cin>>x>>y;
        x--;
        y--;
        tree[x].push_back(y);
    }
    int q;
    cin>>q;
    while(q--){
        cin>>x;
        x--;
        cout<<query(x,tree,tokens)<<endl;
    }
}