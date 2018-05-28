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

//https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
inline vector<string> split(string str,string sep){char* cstr=const_cast<char*>(str.c_str());char* current;vector<string> arr;current=strtok(cstr,sep.c_str());while(current!=NULL){arr.push_back(current);current=strtok(NULL,sep.c_str());}return arr;}
inline bool isPrime(lli n){if (n <= 1){return false;}if (n <= 3)  {return true;}if (n%2 == 0 || n%3 == 0) {return false;}for (int i=5; i*i<=n; i=i+6){if (n%i == 0 || n%(i+2) == 0){return false;}}return true;}
inline lli power(lli x,lli y,lli p){int res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y = y>>1;x = (x*x) % p;}return res;}
inline lli inverse(ll a, ll m){if(a == 0){return -1;}ll exponent = m - 2;ll product = 1;while(exponent){if(exponent & 1){product = (product * a) % m;}a = (a * a) % m;exponent>>=1;}return product;}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    lli t,n,a,b,c,d,e,f,x,y,mod,k;
    cin>>t;
    while(t--){
        cin>>n>>mod>>k;
        vlli A;
        rep(i,n){
            cin>>x;
            A.pb(x);
        }
        vlli v(n);
        for(ll i = 0; i < n; i++){
            v[i] = A[i] % mod;
        }
        ll res = 0;

        if(k == 0){
            //just check for zeroes;
            lli zero = -1;
            for(ll i = 0; i < n; i++){
                if(v[i] == 0) zero = i;
                res += zero + 1;
            }
            cout<<res<<endl;
            continue;
        }
        queue<lli> q1, q2;
        q1.push(0);
        q2.push(n - 1);
        mlli m;        
        while(!q1.empty()){
            auto lo = q1.front(); 
            auto hi = q2.front();
            q1.pop();
            q2.pop();
            if(lo == hi){
                if(v[lo] == k){
                    res++;
                }
                continue;
            }
            m.clear();
            lli mid = (lo + hi)>>1;
            c = 1;
            for(ll i = mid; i >= lo; i--){
                c = (c%mod * v[i]%mod) % mod;
                m[c]++;
            }
            c = 1;
            for(ll i = mid + 1; i <= hi; i++){
                c = (c%mod * v[i]%mod) % mod;
                res += m[(inverse(c, mod) * k) % mod];
            }
            q1.push(lo);
            q2.push(mid);
            q1.push(mid + 1); 
            q2.push(hi);
        }
        cout<<res<<endl;
    }
    bye;
}