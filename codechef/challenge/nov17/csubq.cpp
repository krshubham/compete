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
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )
#define endl '\n'
#define fi first
#define se second

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

inline bool isPrime(lli n){
    if (n <= 1)  {
        return false;
    }
    if (n <= 3)  {
        return true;
    }

    if (n%2 == 0 || n%3 == 0) {
        return false;
    }
    for (int i=5; i*i<=n; i=i+6){
        if (n%i == 0 || n%(i+2) == 0){
            return false;
        }
    }

    return true;
}

const int N=5e5+10;
int n, L, R;


typedef struct node {
    lli v;
    lli n, arr[4], fl;
    node() {
        //constructor
        fl=1;
    }
    lli solve() { 
        return (fl ? 0:v);
    }
    void set(int x) {
        v=0; n=1; fl=0;
        if(x<L) arr[0]=arr[1]=arr[2]=arr[3]=1;
        else if(x>R) arr[0]=arr[1]=arr[2]=arr[3]=0;
        else arr[0]=arr[3]=0, v=arr[1]=arr[2]=1;
    }
    void merge(node left, node right) {
        fl=0;
        if(left.fl && right.fl) fl=1;
        else if(left.fl) 
            *this=right;
        else if(right.fl) 
            *this=left;
        else {
            n = left.n + right.n;
            lli X = left.arr[2] - left.arr[3];
            lli Y = right.arr[1] - right.arr[0];
            v = left.v + right.v + X*right.arr[0] + X*Y + left.arr[3]*Y;
            arr[0] = left.arr[0] + (left.arr[0]==left.n ? right.arr[0]:0);
            arr[1] = left.arr[1] + (left.arr[1]==left.n ? right.arr[1]:0);
            arr[2] = right.arr[2] + (right.arr[2]==right.n ? left.arr[2]:0);
            arr[3] = right.arr[3] + (right.arr[3]==right.n ? left.arr[3]:0);
        }
    }
} Node;
Node segtree[N<<1];


void build() {
    lli i = n;
    while(i--){
        segtree[n+i].set(0);
    }
    i = n;
    while(--i) {
        segtree[i].merge(segtree[i<<1], segtree[i<<1|1]);
    }
}
void update(int p, int v) {
    segtree[n+p].set(v);
    for(int i=n+p;i>>=1;) {
        segtree[i].merge(segtree[i<<1], segtree[i<<1|1]);
    }
}

node query(int l, int r) {
    node left, right;
    for(l+=n,r+=n+1; l<r; l>>=1,r>>=1) {
        if(l&1) left.merge(left, segtree[l++]);
        if(r&1) right.merge(segtree[--r], right);
    }
    left.merge(left,right);
    return left;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t,a,b,c,d,e,f,x,y,q;
    cin>>n>>q>>L>>R;
    build();
    while(q--){
        cin>>t>>x>>y;
        if(t == 1){
            x--;
            update(x,y);
        }
        else{
            x--;
            y--;
            cout<<query(x,y).solve()<<endl;
        }
    }
    bye;
}

