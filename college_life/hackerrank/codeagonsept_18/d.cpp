
/**
* @author: krshubham
* @time: 23:46:01
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

ll MOD=1e9+7;

const int MAXN = 3e2+5;
ll dp[301][301][301];
 
string A,B,C;
 
inline ll cnt(int i,int j,int k,int a,int b){
    if(k<0 or j<0) return 0; 
    if(dp[i][j][k]) { 
        return  dp[i][j][k];   
    }
    
    if(i==0){
        return dp[i][j][k] = (a == 0 && b == 0) ? 1:0;
    } 
    ll ans=0;
    for(int y = j; y > 0;y--){
        if(A[y-1]==C[i-1]) ans = (ans+cnt(i-1,y-1,k,0,b))%MOD;
    }
    for(;k > 0;k--){
        if(B[k-1]==C[i-1]) ans = (ans+cnt(i-1,j,k-1,a,0))%MOD;
    }
    return dp[i][j][k] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>A>>B>>C;
    cout<<cnt(C.size(),A.size(),B.size(),1,1)<<endl;
    bye;
}