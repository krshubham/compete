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

lli c = 0;

char* removeUtil(char *str, char *last_removed){
    if (str[0] == '\0' || str[1] == '\0')
        return str;
    if (str[0] == str[1]){
        *last_removed = str[0];
        while (str[1] && str[0] == str[1])
            str++;
        str++;
        return removeUtil(str, last_removed);
    }
    c++;
    char* rem_str = removeUtil(str+1, last_removed);
    if (rem_str[0] && rem_str[0] == str[0]){
        *last_removed = str[0];
        return (rem_str+1);
    }
    if (rem_str[0] == '\0' && *last_removed == str[0]){
       return rem_str;
   }
   rem_str--;
   rem_str[0] = str[0];
   return rem_str;
}

char *remove(char *str){
    char last_removed = '\0';
    return removeUtil(str, &last_removed);
}

int main(){
    // ios_base::sync_with_stdio(0);
    lli t,n,a,b,d,e,f,x,y;
    cin>>t;
    while(t--){
        c = 0;
        cin>>n;
        char s[n];
        scanf("%s",s);
        remove(s);
        cout<<c<<endl;
    }
    bye;
}

