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
	if (n <= 1){
		return false;
	}
	if (n <= 3){
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
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	vector<string> v;
	vlli blacks(n);
	vlli output(n);
	map<lli,vlli> m;
	vector<int> v1,v2;
	rep(i,n){
		cin>>x;
		v1.pb(x);
		output[i] = i+1;
		v.pb(string(x,'w'));
	}
	rep(i,n){
		cin>>x;
		v2.pb(x);
		rep(j,x){
			v[i].replace(j,1,"b");
		}
	}
	map<int, vector<int>> Mp;
	rep(i,n){
		Mp[v1[i]-v2[i]].push_back(i);
	}
	priority_queue<pair<int,int>> pq;
	for(auto it=Mp.begin();it!=Mp.end();it++){
		pq.push({it->second.size(),it->first});
	}
	rep(i,n){
		cout<<v[i]<<endl;
	}
	int arr[n+5];
	int fir=0,las=n-1;
	while(!pq.empty()){
		auto vc=Mp[pq.top().second];
		int st=0,sz=vc.size()-1;
		int aa=0;
		while(st<=sz){
			if(st==sz){
				arr[fir++]=vc[st++];
			}
			else if(st+1==sz){
				arr[fir++]=vc[st++];
				arr[las--]=vc[sz--];
			}
			else{
				if(aa%2==0){
					if(st+1<sz){
						arr[fir++]=vc[st];
						st++;
					}
					aa=1;
				}
				else{
					if(sz-1>st){
						arr[las--]=vc[sz];
						sz--;
					}
					aa=0;
				}
			}
		}
		pq.pop();
	}
	rep(i,n)
	cout<<arr[i]+1<<" ";
	cout<<endl;
	bye;
}