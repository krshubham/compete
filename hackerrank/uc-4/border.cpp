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

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,q;
	cin>>t;
	string s;
	while(t--){
		map<int,set<string> > ma;
		cin>>n>>q;
		cin>>s;
		vector<string> v(n+1);
		for (int i = 0; i < n; ++i){
			if(i == 0){
				v[i] = s[0];
			}
			else{
				v[i] = v[i-1] + s[i];
			}
			string test = v[i];
			vector<string> pre(n);
			for (int i = 0; i < test.size(); ++i){
				if(i == 0){
					pre[i] = test[0];
				}
				else{
					pre[i] = pre[i-1] + test[i];
				}
			}
			vector<string> suf(n);
			for (int i = test.size()-1; i >= 0; i--){
				if(i == test.size()-1){
					suf[i] = test;
				}
				else{
					string res = suf[i+1];
					res.erase(res.begin());
					suf[i] = res;
				}
			}
			map<string,lli> Mp;
			for (auto i:pre){
				Mp[i]++;
			}
			for(auto i:suf){
				Mp[i]++;
			}
			set<string> st;
			for(auto it=Mp.begin(); it != Mp.end(); it++){
				if(it->second >= 2){
					if(it->first == ""){
						continue;
					}
					st.insert(it->first);
				}
			}
			ma[i] = st;
			// for(auto x:st){
			// 	cout<<x<<endl;
			// }
			// b--;
			// if(b >= st.size()){
			// 	cout<<-1<<endl;
			// 	continue;
			// }
		}
		while(q--){
			cin>>a>>b;
			b--;
			if(b >= ma[a-1].size()){
				cout<<-1<<endl;
			}
			else{
				auto it = ma[a-1].begin();
				advance(it,b);
				cout<<(*it).size()<<endl;
			}
		}
	}
	bye;
}

