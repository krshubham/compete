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
#define rep(i,n) for(int i = 0; i < n; i++)
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

lli n;
const lli MAXN = 1e5+5;
plli arr[MAXN];
lli t,c,d,a,b,e,f,x,y;
plli p1,p2,p3,p4,p5,p6,p7,p8;

inline vector<string> split(string str,string sep){char* cstr=const_cast<char*>(str.c_str());char* current;vector<string> arr;current=strtok(cstr,sep.c_str());while(current!=NULL){arr.pb(current);current=strtok(NULL,sep.c_str());}return arr;}
inline bool isPrime(lli n){if (n <= 1){return false;}if (n <= 3)  {return true;}if (n%2 == 0 || n%3 == 0) {return false;}for (int i=5; i*i<=n; i=i+6){if (n%i == 0 || n%(i+2) == 0){return false;}}return true;}
inline lli power(lli x,lli y,lli p){int res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y = y>>1;x = (x*x) % p;}return res;}
void operator -= (plli &A, plli B) { A.first -= B.first; A.second -= B.second; }
//Reference from : http://codeforces.com/blog/entry/48868
inline lli ccw (plli O, plli A, plli B) { A -= O; B -= O; return 1LL * A.first * B.second - 1LL * A.second * B.first; }
inline bool ok(lli x,lli y){plli p;p.first = x;p.second = y;if(ccw(arr[1], arr[2], p) >= 0) return false;if(ccw(arr[1], arr[n], p) <= 0) return false;lli l = 2, r = n;while(l != r) {lli mid = (l + r)/2;if(ccw(arr[1], arr[mid], p) < 0) l = mid + 1;else r = mid;}if(ccw(arr[l - 1], arr[l], p) >= 0) return false;return true;}


map<plli,bool> visited;
vplli v;

inline void clean(){
    visited.clear();
    v.clear();
}

inline bool solve(){
    clean();
    cin>>n;
    lli tofind = floor(n/10);
    queue<plli> Q;
    cin>>c>>d;
    arr[n].first= c;
    arr[n].second= d;
    Q.push(mp(c,d));
    for(lli i=n-1;i>=1;i--){
        cin>>c>>d;
        arr[i].first = c;
        arr[i].second = d;
        Q.push(mp(c,d));
    }
    lli cnt=0;
    lli ans=0;
    while(!Q.empty() && ans!= tofind){
        plli P = Q.front();
        p1 = mp(P.first+1,P.second+1);
        p2 = mp(P.first+1,P.second);
        p3 = mp(P.first,P.second+1);
        p4 = mp(P.first-1,P.second-1);
        p5 = mp(P.first-1,P.second);
        p6 = mp(P.first,P.second-1);
        p7 = mp(P.first-1,P.second+1);
        p8 = mp(P.first+1,P.second-1);
        Q.pop();
        if(ok(p1.first,p1.second) && visited[p1]!=1){
            visited[p1]=1;
            Q.push(p1);
            v.pb(p1);
            ans++;
            if(ans==tofind)break;
        }
        if(ok(p2.first,p2.second) && visited[p2]!=1){
            visited[p2]=1;
            Q.push(p2);
            v.pb(p2);
            ans++;
            if(ans==tofind)break;
        }
        if(ok(p3.first,p3.second) && visited[p3]!=1){
            visited[p3]=1;
            Q.push(p3);
            v.pb(p3);
            ans++;
            if(ans==tofind)break;
        }
        if(ok(p4.first,p4.second)&& visited[p4]!=1){
            visited[p4]=1;
            Q.push(p4);
            v.pb(p4);
            ans++;
            if(ans == tofind )break;
        }
        if(ok(p5.first,p5.second) && visited[p5]!=1){
            visited[p5]=1;
            Q.push(p5);
            v.pb(p5);
            ans++;
            if(ans==tofind) break;
        }
        if(ok(p6.first,p6.second)&& visited[p6]!=1){
            visited[p6]=1;
            Q.push(p6);
            v.pb(p6);
            ans++;
            if(ans==tofind) break;
        }
        if(ok(p7.first,p7.second) && visited[p7]!=1){
            visited[p7]=1;
            Q.push(p7);
            v.pb(p7);
            ans++;
            if(ans==tofind)break;
        }
        if(ok(p8.first,p8.second) && visited[p8]!=1){
            visited[p8]=1;
            Q.push(p8);
            v.pb(p8);
            ans++;
            if(ans == tofind) break;
        }
    }
    return ans == tofind;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>t;
    rep(i,t){
        if(solve()){
            for(auto it=v.rbegin(); it != v.rend();it++){
                cout<<it->first<<" "<<it->second<<endl;
            }
        }
        else{
            cout<<-1<<endl;
        }
    }
    bye;
}
