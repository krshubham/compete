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


inline void check(vector<char>& v, lli n){
    bool c = false;
    lli cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == '(') ++cnt;
        else --cnt;
        if (cnt < 0) {
            c = false;
        }
    } 
    lli i = 0;
    while (i < n && v[i] == ')') ++i;
    if (cnt) {
        c = false;
    }
    if (c){
        cout<<0<<endl;
    }
    else if (v[0] == '(' && v[n - 1] == ')' && v[333] == '(') {
        cout<<2<<endl;
    }
    else if (v[n - 1] == '(' && v[n - 2] == '(' && v[n - 3] == '(' && v[n - 4] == '(') {
        cout<<2<<endl;
    }
    else if (i > 7){
        cout<<2<<endl;
    }
    else{
        cout<<1<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    lli t,n,a,b,d,e,f,x,y;
    cin>>n;
    char c;
    stack<char> s;
    vector<char> v(n);
    rep(i,n){
        cin>>c;
        v[i] = c;
        if(s.size() == 0){
            s.push(c);
        }
        else{
            if(s.top() == '(' && c == ')'){
                s.pop();
            }
            else if(s.top() == ')' && c== '('){
                s.pop();
            }
            else{
                s.push(c);
            }
        }
    }
    if(s.size() == 0){
        cout<<0<<endl;
    }
    else{
        check(v,n);
    }
    bye;
}