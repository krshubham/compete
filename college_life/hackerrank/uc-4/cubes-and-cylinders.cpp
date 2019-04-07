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
#define R2 1.4142135623730951
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

inline vector<string> split(string str,string sep){char* cstr=const_cast<char*>(str.c_str());char* current;vector<string> arr;current=strtok(cstr,sep.c_str());while(current!=NULL){arr.push_back(current);current=strtok(NULL,sep.c_str());}return arr;}
inline bool isPrime(lli n){if (n <= 1){return false;}if (n <= 3)  {return true;}if (n%2 == 0 || n%3 == 0) {return false;}for (int i=5; i*i<=n; i=i+6){if (n%i == 0 || n%(i+2) == 0){return false;}}return true;}
inline lli power(lli x,lli y,lli p){int res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y = y>>1;x = (x*x) % p;}return res;}

inline book ok(string a, string b){
	int count[NO_OF_CHARS] = {0};
	int i;
	for (i = 0; str1[i] && str2[i];  i++){
		count[str1[i]]++;
		count[str2[i]]--;
	}

	if (str1[i] || str2[i]){
		return false;
	}

	for (i = 0; i < NO_OF_CHARS; i++){
		if (count[i]){
			return false;
		}
		return true;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,d,e,f,x,y,m;
	cin>>n>>m;
	vlli s(n),k(n),r(m),c(m);
	vplli v,con;
	rep(i,n){
		cin>>s[i];
	}
	rep(i,n){
		cin>>k[i];
	}
	rep(i,m){
		cin>>r[i];
	}
	rep(i,m){
		cin>>c[i];
	}
	rep(i,s.size()){
		v.pb(mp(s[i],k[i]));
	}

	rep(i,r.size()){
		con.pb(mp(2*r[i],c[i]));
	}
	sort(all(v));
	sort(all(con));
	lli ans=0,j=0,i=0;
	for(;i<v.size() && j<con.size();){
		if(v[i].second==0){
			i++;
		}
		else{
			if(R2*v[i].first < con[j].first){
				if(v[i].second < con[j].second){
					ans = ans + v[i].second;
					con[j].second = con[j].second-v[i].second;
					v[i].second=0;
				}
				else{
					ans = ans + con[j].second;
					v[i].second = v[i].second-con[j].second;
					con[j].second=0;
					j++;
				}

			}
			else{
				j++;
			}
		}
	}
	cout<<ans<<endl;
	bye;
}

