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
#include <bitset>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828
#define stp(a,b) a.push(b)
#define all(a) a.begin(),a.end()
#define PI 3.1415926535897932384626433832795

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

// inline ulli countBits(ulli num) {
// 	register vector<lli> r(num + 1, 0);
// 	ulli c = 0;
// 	for (int i = 1; i <= num; i ++) {
// 		r[i] = r[i & (i - 1)] + 1;
// 		c += mod(mod(r[i])*mod((i)));
// 	}
// 	return mod(c);
// }

#include <iostream>
#include <bitset>
using namespace std;
 
// macros to generate the lookup table (at compile-time)
#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
#define COUNT_BITS B6(0), B6(1), B6(1), B6(2)
 
// lookup-table to store the number of bits set for each index
// in the table. The macro COUNT_BITS generates the table.
unsigned int lookup[256] = { COUNT_BITS };

int numOfSetBits(int n){ 
    int count = lookup[n & 0xff] +    // consider first 8 bits
        lookup[(n >> 8) & 0xff] +     // consider next 8 bits
        lookup[(n >> 16) & 0xff] +    // consider next 8 bits
        lookup[(n >> 24) & 0xff];    // consider last 8 bits
 
    return count;
}
 
// Count set bits using lookup table
int main(){
	    int n = -1;
	    cout << n << " in binary is " << bitset<32>(n) << endl;
	    cout << "The number of set bits in " << n <<" is "<< numOfSetBits(n) << endl;
 
	    return 0;
}

// inline ulli countBits(int num) {
// 	ulli x;
// 	vector<int> v(num+1,0);
// 	ulli c = 0;
// 	for(int i = 1; i <= num; ++i){
// 		x = v[i & (i-1)]+(1);
// 		v.push_back(x);
// 		c += mod(mod(i)*mod(x));
// 	}
// 	return c;
// }

// int main(){
// 	ios_base::sync_with_stdio(0);
// 	lli t,n,a,b,c,d,e,f,x,y;
// 	cin>>t;
// 	while(t--){
// 		cin>>n;
// 		cout<<countBits(n)<<endl;
// 	}
// 	bye;
// }

