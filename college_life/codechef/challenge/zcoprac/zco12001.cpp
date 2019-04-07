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
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )
#define endl '\n'
#define fi first
#define se second
#define MAXN 100001

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
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
int N, nums[MAXN], match[MAXN], depth = 0;

int main(){
    cin >> N;
    int a = 0, b = -1, c = 0, d = -1;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        if (nums[i] == 1){
            depth++;
            match[depth] = i;

            if (depth > a){
                a = depth;
                b = i;
            }
        } else {
            int len = i - match[depth] + 1;
            if (len > c){
                c = len;
                d = match[depth];
            }

            depth--;
        }
    }
    cout<<a<<" "<<b+1<<" "<<c<<" "<<d+1<<endl;
}
