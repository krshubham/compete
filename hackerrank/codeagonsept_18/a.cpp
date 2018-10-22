/**
* @author: krshubham
* @time: 21:20:35
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

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x,y,z;
        vplli v1,v2;
        rep (i,5){
            cin>>x>>y;
            v1.pb(mp(x,y));
            v2.pb(mp(y,x));
        }
        sort(all(v1));
        sort(all(v2));
        bool f = 0;
        for (int i=0;i<v1.size()-2;i++){
            if (v1[i].first == v1[i+1].first && v1[i].first == v1[i+2].first && abs(v1[i].second-v1[i+1].second) == 1 && abs(v1[i].second-v1[i+2].second) == 2)
                f = 1;
        }
        if (!f){
            cout<<"No"<<endl;
            continue;
        }
        f = 0;
        
        for (int i=0;i<v2.size()-2;i++){
            if (v2[i].first == v2[i+1].first && v2[i].first == v2[i+2].first && abs(v2[i].second-v2[i+1].second) == 1 && abs(v2[i].second-v2[i+2].second) == 2)
                f = 1;
        }
        
        
        if (!f){
            cout<<"No"<<endl;
            continue;
        }
        if(f){
            cout<<"Yes"<<endl;

        }
    }
    bye;
}