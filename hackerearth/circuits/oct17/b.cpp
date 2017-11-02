#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <iomanip>
#include <stack>
#include <climits>
#include <queue>
#include <string>
#include <cstring>
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
inline bool isEven(lli x){
    if(x&1) return false;
    else return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    lli t,n,a,b,c,d,e,f,x,y;
    cin>>n;
    c = -1,d = 0;
    y = 0;
    lli arr[n+2];
    y = 0;
    rep(i,n+1){
        cin>>arr[i];
        if(arr[i] < 0 || arr[i] > 0){ 
            c = i;
        }
        if(i == n){
            if(arr[i]< 0){
                y = -1;
            }
            else if(arr[i] == 0){
                y = 0;
            }
            else{
                y = 1;
            }
        }
    }
    if(c == -1){
        //no positive or negative index
        cout<<0<<" "<<0<<endl;
        bye;
    }
    if(c == 0){
        cout<<arr[0]<<" "<<arr[0]<<endl;
    }
    if(y == -1){
        
    }
    else if(y == 0){
        if(arr[c] < 0){
            cout<<-1<<" "<<1<<endl;
        }
        else{
            cout<<1<<" "<<-1<<endl;
        }
    }
    else{
        cout<<1<<" "<<-1<<endl;
    }
    bye;
}