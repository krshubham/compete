#pragma comment (linker, "/stack:20000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define go(i,a,b) for(long long int i = a; i<=b; i++ )
#define come(i,a,b) for(long long int i = a; i>=b; i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define test() int t; scanf("%d",&t); while(t--)
#define lng long long
#define pf printf
#define sf scanf
#define MAX 1005

int main(){
 test() {
  int m,n;
  sf("%d%d",&m,&n);
  int vis[m][n],dist[m][n];
  int a[m][n];
  go(i,0,m-1)
   go(j,0,n-1) {
    sf("%d",&a[i][j]);
    vis[i][j]=0;
    dist[i][j]=MOD;
   }
  int x,y,ti,ans;
  sf("%d%d%d",&x,&y,&ti);
  x--;
  y--;
  
  pair<int, int> tmp1,tmp,dest=mp(x,y);
  pair<int, pair<int, int> > cur,p2;
  priority_queue < pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >,greater< pair<int, pair<int, int> > > > pq;
  tmp=mp(0,0);
  cur = mp(0,tmp);
  pq.push(cur);
  dist[0][0]=a[0][0];
  while(true) {
   cur = pq.top();
   pq.pop();
   if(cur.second == dest) {
    ans = cur.first;
    break;
   }
   int cx,cy;
   cx=cur.second.first;
   cy=cur.second.second;
   if(vis[cx][cy])
    continue;
   vis[cx][cy]=1;
   if(cy-1>=0 && vis[cx][cy-1]==0 && 
      dist[cx][cy-1] > dist[cx][cy] + a[cx][cy-1]) {
    dist[cx][cy-1] = dist[cx][cy] + a[cx][cy-1];
    tmp = mp(cx,cy-1);
    p2 = mp(dist[cx][cy-1],tmp);
    pq.push(p2);
   }
   
   if(cy+1<n && vis[cx][cy+1]==0 && 
      dist[cx][cy+1] > dist[cx][cy] + a[cx][cy+1]) {
    dist[cx][cy+1] = dist[cx][cy] + a[cx][cy+1];
    tmp = mp(cx,cy+1);
    p2 = mp(dist[cx][cy+1],tmp);
    pq.push(p2);
   }
   
   if(cx-1>=0 && vis[cx-1][cy]==0 && 
      dist[cx-1][cy] > dist[cx][cy] + a[cx-1][cy]) {
    dist[cx-1][cy] = dist[cx][cy] + a[cx-1][cy];
    tmp = mp(cx-1,cy);
    p2 = mp(dist[cx-1][cy],tmp);
    pq.push(p2);
   }
   
   if(cx+1<m && vis[cx+1][cy]==0 && 
      dist[cx+1][cy] > dist[cx][cy] + a[cx+1][cy]) {
    dist[cx+1][cy] = dist[cx][cy] + a[cx+1][cy];
    tmp = mp(cx+1,cy);
    p2 = mp(dist[cx+1][cy],tmp);
    pq.push(p2);
   }
  }
  if(ans>ti)
   pf("NO\n");
  else
   pf("YES\n%d\n",ti-ans);
 }
 return 0;
}