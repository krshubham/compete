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
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )
#define endl '\n'
#define fi first
#define se second

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


list<lli> li[1000000];
lli gen[1000000];
vector<pair<lli,lli> > v;
lli end = 0;
lli arr[1000000+10];
lli visited[10000000];
lli start=0;
lli indx=0;
lli t[10000000];


void build(lli node, lli a, lli b){
	if(a>b) return;
	if (a==b){
		t[node]=gen[a];
		return;
	}
	build(node*2, a, (a+b)/2);
	build(node*2+1,(a+b)/2+1,b);
	t[node]=t[node*2]+t[node*2+1];
}

lli  query(lli node, lli a, lli b, lli i, lli j){
	if(a>b||a>j||b<i) return 0;
	
	if (a>=i && b<=j) return t[node];

	lli q1=query(node*2, a, (a+b)/2, i, j);


	lli q2=query(node*2+1, (a+b)/2+1, b, i, j);

	return q1+q2;
}


void update(lli node, lli a, lli b, lli i, lli j,  lli inc){
	if(a>b) return;

	if(a>b||a>j||b<i) return;

	if (a>=i && b<=j){
		t[node]=inc;
		return;
	}
	update(node*2, a, (a+b)/2, i, j, inc);
	update(node*2+1, (a+b)/2+1, b,i, j, inc);
	t[node] = t[node*2] + t[node*2+1];

}
void dfs(lli node){
	end++;
	start++;
	gen[indx]=arr[node];
	indx++;
	v[node].first=start;
	list<lli>:: iterator it;

	for(it=li[node].begin();it!=li[node].end();it++){
		if(!visited[*it]){
			visited[*it]=1;
			dfs(*it);
		}
	}
	v[node].second=end;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,m;
	cin>>n>>m;

	for(lli i=1;i<=n;i++){
		cin>>arr[i];
	}
	v.pb(mp(0,0));
	for(lli i=1;i<n;i++){
		v.pb(mp(0,0));
		lli a,b;
		cin>>a>>b;
		li[a].pb(b);
		li[b].pb(a);
	}

	v.pb(mp(0,0));
	visited[1]=1;
	dfs(1);
	build(1,0,n-1);
	while(m--){
		char c;
		cin>>c;
		if(c=='Q'){
			lli node ;
			cin>>node;
			lli ans= query(1,0,n-1,v[node].first-1,v[node].second-1);
			cout<<ans<<endl;
		}
		else{
			lli a,b;
			cin>>a>>b;
			update(1,0,n-1,v[a].first-1,v[a].first-1,b);
		}
	}	
	bye;
}
