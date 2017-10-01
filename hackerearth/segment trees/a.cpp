//Range Minimum Query

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

#define SIZE 200000

lli tree[4*SIZE];
lli arr[SIZE];

// build the seg tree for storing the min of each interval
void build(lli node, lli begin, lli end){
	if(begin == end){
		tree[node] = arr[begin];
	}
	else{
		lli mid = (begin+end)/2;
		build(2*node, begin,mid);
		build(2*node+1,mid+1,end);
		tree[node] = min(tree[2*node],tree[2*node+1]);
	}
}



lli query(lli node,lli begin, lli end,lli left, lli right){
	if(right > begin || begin < left){
		return 0;
	}
	if(left <= begin && right >= end){
		return tree[node];
	}
	lli mid = begin+end/2;
	lli p1 = query(2*node,begin, mid,left,right);
	lli p2 = query(2*node, mid+1,end, left, right);
	return min(p1,p2);
}

void update(lli x, lli y){
	cout<<x<<y<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>a>>b;
	char s;
	for (int i = 1; i <= a; ++i){
		cin>>arr[i];
	}
	build(1,1,a);
	while(b--){
		cin>>s>>x>>y;
		if(s == 'q'){
			cout<<query(1,1,a,x,y)<<endl;
		}
		else{
			update(x,y);
		}
	}
	bye;
}

