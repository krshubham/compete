#include <iostream>
#include <bitset>
#include <vector>
#include <climits>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define srep(i, begin, end) for (__typeof(end) i = begin; i != end; i++)
#define si(x) int x = scanInt();
#define sll(x) LL x = scanLong();
#define pi(x) printf("%d ", x)
#define pll(x) printf("%lld ", x)
#define nl printf("\n")
#define all(v) v.begin(), v.end()
using namespace std;
typedef long int LI; // 32 bit integer
typedef unsigned long int ULI; // 32 bit unsigned integer
typedef long long int LL; // 64 bit integer
typedef unsigned long long int  ULL; // 64 bit unsigned integer
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
LL mod = 1e9+7;

/* Fast I/O */
inline int scanInt() {
 int n = 0;
 char ch = getchar_unlocked();
 int sign = 1;
 while(ch < '0' || ch > '9') {
  if(ch == '-') sign = -1;
  ch = getchar_unlocked();
}
while(ch >= '0' && ch <= '9') {
  n = (n<<1)+(n<<3)+(int)(ch-'0');
  ch = getchar_unlocked();
}
return n*sign;
}

inline LL scanLong() {
 LL n = 0;
 char ch = getchar_unlocked();
 LL sign = 1;
 while(ch < '0' || ch > '9') {
  if(ch == '-') sign = -1;
  ch = getchar_unlocked();
}
while(ch >= '0' && ch <= '9') {
  n = (n<<1)+(n<<3)+(LL)(ch-'0');
  ch = getchar_unlocked();
}
return n*sign;
}

bitset<2010> g[2010];
int main() {
 sll(n);
 rep(i, 0, n) {
  rep(j, 0, n) {
   sll(x);
   g[i][j] = (x==1);
 }
}
LL ans = 0;
rep(i, 0, n) {
  rep(j, i+1, n) {
   LL cnt = (g[i]&g[j]).count();
   ans += cnt*(cnt-1)/2;
 }
}
cout << ans/2 << endl;
}