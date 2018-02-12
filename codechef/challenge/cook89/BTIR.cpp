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

int main(){
	ios_base::sync_with_stdio(0);
	int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int nSum=0;
        vector<int> v(n);
        vector<int> count(4);
 
        for (int i=0;i<n;i++) {
            int tmp;
            cin >> tmp;
            v[i] = tmp%4;
            nSum += v[i];
            count[v[i]]++;
        }
        if (nSum%4 != 0) {
            cout << -1 << endl;
            continue;
        }
        int c=0;
        if (count[3]>0 and count[1]>0) {
            c += min(count[3], count[1]);
            int x = min(count[3], count[1]);
            count[3]=count[3]-x;
            count[1]=count[1]-x;
        }
        
        if (count[2]>0) {
            int x = count[2]/2;
            c+= x;
            x = x * 2;
            count[2]=count[2]-x;
        }
        if (count[2]>0) {
            if (count[1]>0) {
                c+=2;
                count[2]--;
                count[1]=count[1]-2;
            }
            if (count[3]>0) {
                c+=2;
                count[2]--;
                count[3]=count[3]-2;
            }
        }
        
        if (count[3]>0) {
            int x = count[3]/4;
            c += x * 3;
            x = x * 4;
            count[3]=count[3] - x;
        }
        if (count[1]>0) {
            int x = count[1]/4;
            c += x * 3;
            x = x * 4;
            count[1]=count[1] - x;
        }
        cout<<c<<endl;
    }
	bye;
}

