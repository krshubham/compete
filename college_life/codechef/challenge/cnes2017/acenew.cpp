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

int countTriplets(lli arr[], lli n, lli sum){
    // Sort input array
	sort(arr, arr+n);

    // Initialize result
	int ans = 0;

    // Every iteration of loop counts triplet with
    // first element as arr[i].
	for (int i = 0; i < n - 2; i++){
        // Initialize other two elements as corner elements
        // of subarray arr[j+1..k]
		int j = i + 1, k = n - 1;

        // Use Meet in the Middle concept
		while (j < k){
            // If sum of current triplet is more or equal,
            // move right corner to look for smaller values
			if (arr[i] + arr[j] + arr[k] <= sum)
				k++;
            // Else move left corner
			else{
                // This is important. For current i and j, there
                // can be total k-j third elements.
				ans += (k - j);
				j--;
			}
		}
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		cin>>n;
		lli arr[n];
		rep(i,n){
			cin>>arr[i];
		}
		cin>>a;
		c = 0;
		// 
		cout<<countTriplets(arr,n,a)<<endl;
	}
	bye;
}

