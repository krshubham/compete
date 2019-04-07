/*
* @Author: krshubham
* @Date:   2018-03-24 11:20:40
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-24 12:07:36
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
vector<pair<int,int> > graph[MAXN];


inline int shortestPath(int src, int dest){ 
	priority_queue<int,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	vector<int> dist(MAXN,MAXN);
	pq.push({0,src});
	dist[src] = 0;
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for(auto it = graph[u].begin(); it != graph[u].end(); it++){
			int v = it->first;
			int w = it->second;
			if(dist[v] > dist[u]+w){
				dist[v] = dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
	return dist[dest];
}


int main(int argc, char const *argv[]){
	int edges,nodes,source,dest;
	cin>>nodes>>edges;
	int x,y,w;
	for (int i = 0; i < edges; ++i){
		cin>>x>>y>>w;
		graph[x].push_back(make_pair(y,w));
		graph[y].push_back({x,w});
	}
	cin>>source>>dest;
	cout<<shortestPath(source,dest)<<endl;
	return 0;
}
