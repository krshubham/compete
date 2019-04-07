#include <bits/stdc++.h>
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

inline int binSearch(int arr[],int val,int b){
	int low=0,high=b-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]>val){
			high=mid-1;
		}
		else if(arr[mid]<val){
			low=mid+1;
		}
		else{
			return 1;
		}
	}
	return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,m,x,y,z;
		cin>>n>>m;
		priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>pq;
		priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>test;

		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				cin>>x;
				pq.push(mp(x,mp(i,j)));
			}
		}
		ll a[n];
		ll b[m];
		ll ans;
		ll t,res=INT_MAX;
		for (int i=0;i<n*m;i++){
			fill(a,a+n+1,0);
			fill(b,b+m+1,0);
			ans = 0;
			test = pq;
			while (!test.empty()){
				x = test.top().first;
				y = test.top().second.second;
				z = test.top().second.first;
				if (b[y] == 0 && a[z] == 0){
					ans += x;
					b[y] = 1;
					a[z] = 1;
				}
				test.pop();
			}

			for (int j=0;j<m;j++){
				if (b[j] == 0){
					t = 1;
					break;
				}
				else
					t = 0;
			}

			if (t == 0)
				res = min(ans,res);

			pq.pop();
		}

		cout<<res<<endl;
	}
}