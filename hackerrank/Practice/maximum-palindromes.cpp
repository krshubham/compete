#pragma comment (linker, "/stack:20000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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

const lli N = 1e5+10;
const lli A = 26;

lli dp[N][A];
lli fact[N], invfact[N];

ll power(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return power(x, y - 1) * x % MOD;
    } else {
        ll tmp = power(x, y / 2);
        return tmp * tmp % MOD;
    }
}

inline void pre(){
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invfact[i] = power(fact[i], MOD - 2);
    }
}

inline lli solve(lli l, lli r){
    lli sum = 0;
    lli odd = 0;
    ll res = 1;
    for (lli i = 0; i < A; i++) {
        lli cur = dp[r][i] - dp[l - 1][i];
        sum += cur / 2;
        res = res * invfact[cur / 2] % MOD;
        if (cur % 2 == 1) {
            odd++;
        }
    }
    res = res * max(1LL, odd) % MOD;
    res = res * fact[sum] % MOD;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    lli t,n,a,b,c,d,e,f,x,y,q;
    pre();
    string s;
    cin>>s>>q;
    memset(dp, 0, sizeof dp);
    x = s.size();
    {
        lli j = 0;
        for(char i:s){
            dp[++j][i-'a']++;
        }
    }
    for (int i = 1; i <= x; ++i){
        for (int j = 0; j < A; ++j){
            dp[i][j] += dp[i-1][j];
        }
    }
    while(q--){
        cin>>a>>b;
        cout<<solve(a,b)<<endl;
    }
    bye;
}

