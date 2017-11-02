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

long long int maxProduct(int arr[] , int n){
    // An array ti store  closest smaller element on left
    // side of every element. If there is no such element
    // on left side, then smaller[i] be -1.
	int smaller[n];
    smaller[0] = -1 ;// no smaller element on right side

    // create an empty set to store visited elements from
    // left side. Set can also quickly find largest smaller
    // of an element.
    set<int>S ;
    for (int i = 0; i < n ; i++)
    {
        // insert arr[i] into the set S
    	auto j =  S.insert(arr[i]);
        auto itc = j.first; // points to current element in set

        --itc; // point to prev element in S

        // If current element has previous element
        // then its first previous element is closest
        // smaller element (Note : set keeps elements
        // in sorted order)
        if (itc != S.end())
        	smaller[i] = *itc;
        else
        	smaller[i] = -1;
    }

    // Initialize result
    long long int result = INT_MIN;

    // Initialize greatest on right side.
    int max_right = arr[n-1];

    // This loop finds greatest element on right side
    // for every element. It also updates result when
    // required.
    for (int i=n-2 ; i >= 1; i--){
        // If current element is greater than all
        // elements on right side, update max_right
    	if (arr[i] > max_right)
    		max_right = arr[i];

        // If there is a greater element on right side
        // and there is a smaller on left side, update
        // result.
    	else if (smaller[i] != -1)
    		result = max((lli)smaller[i] * arr[i] * max_right,
    			result);
    }
    if(result == INT_MIN){
        result = 0;
    }
    return result;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,a,b,c,d,e,f,x,y;
	int n;
	cin>>n;
	int v[n];
	rep(i,n){
		cin>>v[i];
	}
	cout<<maxProduct(v,n)<<endl;
	// for (int i = 0; i < n; ++i){
	// 	for (int j = i+1; j < n; ++j){
	// 		for (int k = j+1; k < n; ++k){
	// 			if(v[i] < v[j] && v[j] < v[k] && v[i] < v[k]){
	// 				c = max(c,v[i]*v[j]*v[k]);
	// 			}
	// 		}
	// 	}
	// }
	// cout<<c<<endl;
	bye;
}

