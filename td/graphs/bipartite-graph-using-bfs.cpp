/**
* @author: krshubham
* @time: 22:47:51
**/
#pragma comment (linker, "/stack:20000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828
#define stp(a,b) a.push(b)
#define all(a) a.begin(),a.end()
#define PI 3.1415926535897932384626433832795
#define rep(i,n) for( int i = 0; i < n; i++ )
#define endl '\n'

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef unsigned long long ull;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef unordered_map<lli,lli> umlli;
typedef vector<pair<lli,lli> > vplli;
inline vector<string> split(string str,string sep){char* cstr=const_cast<char*>(str.c_str());char* current;vector<string> arr;current=strtok(cstr,sep.c_str());while(current!=NULL){arr.push_back(current);current=strtok(NULL,sep.c_str());}return arr;}
inline bool isPrime(lli n){if (n <= 1){return false;}if (n <= 3)  {return true;}if (n%2 == 0 || n%3 == 0) {return false;}for (int i=5; i*i<=n; i=i+6){if (n%i == 0 || n%(i+2) == 0){return false;}}return true;}
inline lli power(lli x,lli y,lli p){int res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y = y>>1;x = (x*x) % p;}return res;}

const int MAXN = 1e5+5;

vlli graph[MAXN];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    lli t,n,a,b,c,d,e,f,x,y,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    bool visited[MAXN];
    int level[MAXN];
    fill(visited,visited+MAXN,false);
    fill(level,level+MAXN,-1);
    level[1] = 0;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        auto x = Q.front();
        Q.pop();
        visited[x] = true;
        for(auto child:graph[x]){
            if(!visited[child]){
                visited[child] = true;
                level[child] = level[x]+1;
                Q.push(child);
            }
            else if(level[child] == level[x]){
                cout<<"the graph is not bi partite"<<endl;
                bye;
            }
        }
    }
    cout<<"The graph is bipartite"<<endl;
    bye;
}