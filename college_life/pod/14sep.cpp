#include <bits/stdc++.h>
using namespace std;


int main(){
    int fnum;
    int height;
    int dia;
    int k;
    cin>>fnum>>height>>dia>>k;
    int x,y;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0; i < k; i++){
        cin>>x>>y;
        if(x == dia){
            pq.push(y);
        }
    }
    int cost = 0;
    while(pq.size() > 1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        cost += (x+y);
        pq.push(x+y);
    }
    cout<<cost<<endl;
    return 0;
}