#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define end return 0
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define mset(c,v) memset(c , v , sizeof c)

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;

const ll high = 100005;

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}


ll A[high], B[high], C[high], sumA[high], sumC[high];
vlli fromA, fromC;

int main(){
	ios_base::sync_with_stdio(0);
	int lenA, lenB, lenC, test , i, pos , n , tmplen=0,t;
	long long cal=0 , ans=0;
	cin>>t;
	while(t--){
		fromA.clear();
		fromC.clear();
		mset(A, 0);
		mset(B, 0);
		mset(C, 0);
		mset(sumA, 0);
		mset(sumC, 0);
		cal = 0;
		ans = 0;

		cin>>lenA>>lenB>>lenC;

		for(int i=0; i<lenA; i++) cin>>A[i];
		for(int i=0; i<lenB; i++) cin>>B[i];
		for(int i=0; i<lenC; i++) cin>>C[i];
		
		sort(A, A+lenA);
		sort(B, B+lenB);
		sort(C, C+lenC);

   
		sumA[0] = A[0] % mod;
		sumC[0] = C[0] % mod;
		for(i=1; i<lenA; i++) sumA[i] = ((sumA[i-1] % mod) + (A[i] % mod)) % mod;
		for(i=1; i<lenC; i++) sumC[i] = ((sumC[i-1] % mod) + (C[i] % mod)) % mod;
			for(i=0; i<lenB; i++){
				pos = upper_bound(A, A+lenA, B[i]) - A;
				n = pos;
				if(pos>0){
					pos--;
					cal = ((sumA[pos] % mod) + (((n%mod) * (B[i])) % mod)) % mod;
					fromA.push_back(cal);
				}
				else fromA.push_back(0);
			}
			for(i=0; i<lenB; i++){
				pos = upper_bound(C, C+lenC, B[i])-C;
				n = pos;
				if(pos > 0){
					pos--;
					cal = (sumC[pos]%mod + (((n%mod) * (B[i] % mod)) % mod)) % mod;
					fromC.push_back(cal);
				}
				else fromC.push_back(0);
			}
			tmplen = fromA.size();
			for(i=0; i<tmplen; i++){
				ans = ((ans % mod) + ((fromA[i] % mod) * (fromC[i] % mod) % mod)) % mod;
			}
			cout<<ans<<endl;
		}
	end;
}
