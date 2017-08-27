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
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828

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
  lli t;
  cin>>t;
  while(t--){
    lli n,c=0,i,j,k;
    cin>>n;
    string a[n];
    for(i=0;i<n;i++){
     cin>>a[i];
   }
   for(i=0;i<n;i++){
     for(j=0,k=n-1;j<=k;j++,k--){
      if(a[i][j]!=a[i][k]){
       cout<<"NO"<<endl;
       c=1;
       break;
     }
   }
   if(c==1)
     break;
 }
 if(c!=1){
   for(i=0;i<n;i++){
     for(j=0,k=n-1;j<=k;j++,k--){
      if(a[j][i]!=a[k][i]){
       cout<<"NO"<<endl;
       c=1;
       break;
     }
   }
   if(c==1) break;
 }
}
if(c==0)
  cout<<"YES"<<endl;
}
bye;
}

