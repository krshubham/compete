/**
* @author: krshubham
* @time: 23:02:33
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
int parent[MAXN];
int size[MAXN];
int val[MAXN];
multiset<int> vals[MAXN];

void make_set(int u){
    parent[u] = u;
    size[u] = 1;
    vals[u].insert(val[v]);
}

void merge(int a, int b){
    for(auto it:vals[b]){
        vals[a].insert(it);
    }
    vals[b].clear();
}

int find_set(int u){
    if(u == parent[u]){
        return u;
    }
    parent[u] = find_set(parent[u]);
}

void union_sets(int u, int v){
    int a = find_set(u);
    int b = find_set(v);
    if(a != b){
        if(size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        marge(a,b);
        size[a] += size[b];
        size[b] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    lli t,n,a,b,c,d,e,f,x,y;
    cin>>n;
    vplli v(n+1);
    rep(i,n-1){
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    rep(i,n){
        cin>>val[i];
    }
    vlli rem(n);
    rep(i,n-1){
        cin>>rem[i];
    }
    rep(i,n+2){
        make_set(i);
    }
    int _max = 0;
    bye;
}