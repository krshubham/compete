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

inline vector<string> split(string str,string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

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

const lli MAXN = 3e5+5;

lli n,arr[MAXN];


int main(){
    ios_base::sync_with_stdio(0);
    lli t,n,a,b,c,d,e,f,x,y;
    cin>>n;

    rep(i,n){
        cin>>arr[i];
    }
    cin>>t;
    vplli queries;
    rep(i,t){
        cin>>x>>y;
        queries.pb(mp(x,y));
    }
    c = 0;
    set<plli> seen;
    map<plli,lli> m;
    rep(i,t){
        if(seen.find(queries[i]) != seen.end()){
            x = m[queries[i]];
            c += x*(i+1);
            c = mod(c);
            continue;
        }
        else{
            seen.insert(queries[i]);
        }
        arr[queries[i].first - 1] = queries[i].second;
        vlli test(arr,arr+n);
        sort(all(test));
        x = 0,y = 0,e = 0,f = 0;
        while(y < n){
            lli cnt = 1;
            for (int j = y+1; j < n; ++j){
                if(test[j] == test[y]){
                    cnt++;
                }
            }
            y += cnt;
            x += cnt;
            while(y < n){
                if(test[y] - test[y-1] == 1){
                    lli testcnt = 1;
                    for (int j = y+1; j < n; ++j){
                        if(test[j] == test[y]){
                            testcnt++;
                        }
                    }
                    if(testcnt > cnt){
                        x += (testcnt - cnt);
                    }
                    cnt = testcnt;
                    y += testcnt;
                }
                else{
                    break;
                }
            }
        }
        m[queries[i]] = x;
        c += x*(i+1);
        c = mod(c);
    }
    cout<<c<<endl;
    bye;
}

