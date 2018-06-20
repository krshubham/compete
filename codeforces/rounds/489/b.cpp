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

//Reference from http://www.techiedelight.com/blog/345612
inline vector<string> split(string str,string sep){char* cstr=const_cast<char*>(str.c_str());char* current;vector<string> arr;current=strtok(cstr,sep.c_str());while(current!=NULL){arr.push_back(current);current=strtok(NULL,sep.c_str());}return arr;}
inline bool isPrime(lli n){if (n <= 1){return false;}if (n <= 3)  {return true;}if (n%2 == 0 || n%3 == 0) {return false;}for (int i=5; i*i<=n; i=i+6){if (n%i == 0 || n%(i+2) == 0){return false;}}return true;}
inline lli power(lli x,lli y,lli p){int res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y = y>>1;x = (x*x) % p;}return res;}
inline lli lcm(lli m, ll n){ return m*n/__gcd(m,n);}

inline int totalPrimeFactors(int n,int l,int r){
    int count = 0;
    if (!(n%2) && 2 >= l && 2 <= r){
        count++;
        while (!(n%2))
            n /= 2;
    }
    for (int i = 3 ; i*i <= min(n,r); i = i+2){
        if (!(n%i)){
            count++;
            while (!(n%i))
                n /= i;
        }
    }
    if (n > 2 && n >=l && n <= r) count++;
    return count;
}
inline lli countPairs(lli G, lli L,lli l,lli r){
    if (L % G != 0)
       return 0;
    lli div = L/G;
    lli k = totalPrimeFactors(div,l,r);
    return k ? (1 << k) : 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ulli t,n,a,b,c,d,e,f,x,y,l,r;
    cin>>l>>r>>x>>y;
    // n = x*y;
    // c = 0;
    // for (ulli i = l; i <= sqrt(n) ; i++){
    //     // if (n%i == 0){
    //     //     if (n/i != i){
    //     //         if(__gcd(i,n/i) == 1 && i >= l and n/i >= l and i <= r and n/i <= r){
    //     //             c+=2;
    //     //         }
    //     //     }
    //     // }
    //     if(n > r*i) break;
    //     if((n/i)*i == n){
    //         a = __gcd(i,n/i);
    //         if(a == x){
    //             if(i == n/i){
    //                 c++;
    //             }
    //             else{
    //                 c += 2;
    //             }
    //         }
    //     }
    // }
    // cout<<c<<endl;
    cout<<countPairs(x,y,l,r)<<endl;
    bye;
}