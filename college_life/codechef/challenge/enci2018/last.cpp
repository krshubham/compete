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

// int main(){
//     ios_base::sync_with_stdio(0);
//     lli t,n,a,b,c,d,e,f,x,y;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         lli arr[n];
//         rep(i,n){
//             cin>>arr[i];
//         }
//         lli dp[n+5];
//         c = 0;
//         for (int i = n-1; i >= n-3; i--){
//             c += arr[i];
//             dp[i] = c;
//         }
//         for(int i = n-2;i>=0;i--){
//             long sum=0,maxi=0,cur;
//             for(int j=0;j<=3;j++){
//                 cur = sum;
//                 if((i+j+1)<n){
//                     cur += dp[i+j+1];  
//                 }
//                 if(cur > maxi) {
//                     maxi = cur;
//                 }
//                 sum += arr[i+j];
//             }
//             dp[i] = maxi;
//         }
//         cout<<dp[0]<<endl;
//     }
//     bye;
// }


long maxsum(int n,int k,long sums[]){
    long maxsums[n];
    int i;
    long add  = 0;
    for(i=n-1;i>=n-k;i--){
        add += sums[i];
        maxsums[i] = add;
    }

    for(i = n-k-1;i>=0;i--){
        int j;
        long sum =0,max = 0,cur;
        for(j=0;j<=k;j++){
            cur = sum;
            if((i+j+1)<n)
                cur += maxsums[i+j+1];  
            if(cur > max) max = cur;
            sum += sums[i+j];
        }
        maxsums[i] = max;
    }
    return maxsums[0];
}

int main(){
    lli t,n,a,b,c,d,e,f,x,y;
    cin>>t;
    while(t--){
        cin>>n;
        long arr[n];
        rep(i,n){
            cin>>arr[i];
        }
        cout<<maxsum(n,3,arr)<<endl;
    }
}