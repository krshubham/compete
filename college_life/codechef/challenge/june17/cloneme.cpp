#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
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
	if (n <= 1) {
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
	if(x&1) {
		return false;
	}
	else{
		return true;
	} 

}

vlli tree[4*112233];
lli arr[112233];

vlli merge(vlli arr1,vlli arr2){
	int i = 0, j = 0, k = 0;
	lli n1 = arr1.size();
	lli n2 = arr2.size();
    // Traverse both array
    vlli arr3(n1+n2);
	while (i<n1 && j <n2){
		if (arr1[i] < arr2[j]){
			arr3[k++] = arr1[i++];
		}
		else{
			arr3[k++] = arr2[j++];
		}
	}

    // Store remaining elements of first array
	while (i < n1){
		arr3[k++] = arr1[i++];
	}

    // Store remaining elements of second array
	while (j < n2){
		arr3[k++] = arr2[j++];
	}
	return arr3;
}

void build(lli cur, lli l,lli r){
	if(l == r){
		tree[cur].pb(arr[l]);
		return;
	}
	int mid = l+(r-l)/2;
	build(2*cur+1 , l , mid ); // Build left tree 
	build(2*cur+2 , mid+1 , r ); // Build right tree
	tree[cur] = merge( tree[2*cur+1] , tree[2*cur+2] ); //Merging the two sorted arrays
}


int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,q;
	cin>>t;
	while(t--){
		cin>>n>>q;
		for (int i = 0; i < n; ++i){
			cin>>arr[i];
		}
		build(1,0,n-1);
		for (int i = 0; i < count; ++i){
			/* code */
		}
	}
	bye;
}
