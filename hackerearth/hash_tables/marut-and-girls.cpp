#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m, v;
	unordered_set<int> mp;
	vector<int> V(10005, 0);
	bool visited[10005];
	scanf("%d",&m);
	for(int i = 0; i != m; ++i){
		scanf("%d",&v);
		V[v] = 1;
	}
	scanf("%d",&n);
	int ans = 0;
	getchar();
	while(n--){
		char c;
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		while(true){
			scanf("%d",&v);
			if(V[v]== 1 && !visited[v]){ cnt++;
				visited[v] = true;
			}
			c = getchar();
			if(c == ' ') continue;
			else break;
		}
		if(cnt == m) ans++;
	}
	printf("%d\n",ans);
}