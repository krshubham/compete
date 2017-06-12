//a good problem based on segment tree with each node as a vector
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

inline bool isPrime(lli n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
         return false;

     return true;
 }

 inline bool isEven(lli x){
   if(x&1) return false;
   else return true;
}


lli arr[1122345];
vlli tree[4*112345];
vlli primes;

void merge(lli x,lli a, lli b){
    //utility function to join the two parts
    lli i = 0,j = 0;
    while(i < tree[a].size() && j < tree[b].size()){
        if(tree[a][i] < tree[b][j]){
            tree[x].pb(tree[a][i]);
            i++;
        }
        else{
            tree[x].pb(tree[b][j]);
            j++;
        }
    }
    while(i < tree[a].size()){
        tree[x].pb(tree[a][i]);
        i++;
    }
    while(j < tree[b].size()){
        tree[x].pb(tree[b][j]);
        j++;
    }
}

void build(lli cur, lli l, lli r){
    if(l == r){
        for(lli p: primes){
            while(arr[l]%p == 0){
                arr[l] /= p;
                tree[cur].pb(p);
            }
        }
        if(arr[l] != 1){
            tree[cur].pb(arr[l]);
        }
        return ;
    }
    lli mid = (l+r)/2;
    build(2*cur,l,mid);
    build(2*cur + 1, mid+1, r);
    merge(cur, 2*cur, 2*cur+1);
}


lli query(lli cur, lli i, lli j, lli l, lli r, lli x, lli y){
    if(i > r || j < l)
        return 0;
    if(i >= l && j <= r){
        lli lb = lower_bound(tree[cur].begin(), tree[cur].end(), x) - tree[cur].begin();            
        lli ub = upper_bound(tree[cur].begin(), tree[cur].end(), y) - tree[cur].begin() - 1;
        return ub - lb + 1;
    }
    lli mid = (i + j)/2;
    //overlapping on both the intervals
    return query(cur*2, i, mid, l, r, x, y) + query(cur*2+1, mid+1, j, l, r, x, y);
}



int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,m,a,b,c,d,e,f,x,y,l,r;
    for(int p=2;p<2000;p++){
        if(isPrime(p)){
            primes.pb(p);
        }
    }
    cin>>n;
    for (int i = 0; i < n; ++i){
        cin>>arr[i];
    }
    build(1,0,n-1);
    cin>>m;
    for (int i = 0; i < m; ++i){
        cin>>l>>r>>x>>y;
        l--;r--;
        cout<<query(1,0,n-1,l,r,x,y)<<endl;
    }
	bye;
}
