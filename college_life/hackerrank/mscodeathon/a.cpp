#include <iostream>
#include <vector>
#include <algorithm>
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
#define endl '\n'
#define fi first
#define se second

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef vector<lli> vlli;

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>a>>b>>c;
	lli arr[a],brr[a];
	rep(i,a){
		cin>>arr[i];
	}
	rep(i,a){
		cin>>brr[i];
	}
	x = 0;
	x = b*c;
	rep(i,a){
		x = max(x,arr[i]*brr[i]*b);
	}
	cout<<x<<endl;
	bye;
}


