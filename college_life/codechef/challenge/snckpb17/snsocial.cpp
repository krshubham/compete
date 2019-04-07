#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <list>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
using namespace std;


lli arr[1003][1003];
lli x[]={0,0,1,-1,1,1,-1,-1};
lli y[]={1,-1,0,0,1,-1,1,-1};

lli getmax(lli r,lli c){
	lli max1=INT_MIN;
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			max1=max(max1,arr[i][j]);			
		}
	}
	return max1;
}
lli bfs(lli r,lli c,lli z){
	list<plli> q;
	int vis[r+2][c+2];
	q.clear();
	lli cnt=0;
	for (int i = 0; i < r; ++i){
		for (int j = 0; i < c; ++j){
			vis[i][j]=0;
			if(arr[i][j]==z)
			{
				plli temp;
				temp.first=i;
				temp.second=j;
				q.push_back(temp);
				vis[i][j]=1;
				cnt++;
			}		
		}
	}
	list<plli>::iterator it;  
	lli ans=0;
	while(!q.empty()){
		if(cnt==0){
			ans++;
			cnt=q.size();
		}
		cnt--;
		it=q.begin();
		q.pop_front();
		plli z = *it;
		lli x1=z.first,y1=z.second;
		for (int i = 0; i < 8; ++i){
			lli a=x1+x[i];
			lli b=y1+y[i];
			if(a>=0 && a<r && b>=0 && b<c && vis[a][b]==0){
				vis[a][b]=1;
				z.first=a;
				z.second=b;
				q.push_back(z);
			}	
		}
	}
	return ans;    
}
int main(){
	ios_base::sync_with_stdio(0);
	lli t;
	cin>>t;
	while(t--){
		lli r,c;
		cin>>r>>c;
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j){
				cin>>arr[i][j];
			}
		}
		lli z = getmax(r,c);
		cout<<bfs(r,c,z)<<endl;
	}
}