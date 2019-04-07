#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked

#define ll long long
#define ld long double

typedef pair<int, int>	pi;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pi>		vpi;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)

#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define slen(s) strlen(s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define boostIO ios_base::sync_with_stdio(false), cin.tie(0)
#define tc(t) ll t; cin >> t; while(t--)
#define PI 3.1415926535897932384626
#define beg int main()
#define ret return 0
#define bye exit(0)
#define nxl <<endl
#define show cout<<
#define INF 0x3f3f3f3f
#define MAX 200000
#define mod 1000000007

bool yoyo(const pll p1 ,const pll p2){
    // return int(p1) > int(p2);
	return p1.F>p2.F;

}

beg{

	ll n,i,j,k,m,a;
	cin>>n>>k>>m;
	ld arr[m+1][n+2];
	ld cost[n+2];

	vector<vector<pair<ld,ld> > > yo;
	vector<pair<ld,ld> > con;

	ld su[n+2];
	fo(i,m){
		fo(j,n){
			cin>>arr[i][j];
			su[j]+=arr[i][j]; 
		}
	}
	fo(i,n){
		cin>>cost[i];
		su[i] -= ((ld)(cost[i]) + (ld)sqrt(sqrt(cost[i]) + (ld)log2(cost[i])))*(ld)log2(cost[i])*(ld)sqrt(cost[i])*(0.85);
		con.pb(mp(su[i],i));
	}

	sort(all(con),yoyo);

	ll rem = k;
	fo(i,con.size()){
		cout<<con[i].S+1<<" ";
		rem--;
		if(rem==0) break;
	}
	ret;
}