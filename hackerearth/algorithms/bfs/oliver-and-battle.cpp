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

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		cin>>a>>b;
		lli arr[a+2][b+2];
		rep(i,a){
			rep(j,b){
				cin>>arr[i][j];
			}
		}
		lli visited[a+2][b+2];
		rep(i,a+2){
			rep(j,b+2){
				visited[i][j] = 0;
			}
		}
		x = 0;
		d = 0;
		rep(i,a){
			rep(j,b){
				if(arr[i][j] == 1 && visited[i][j] != 1){
					x++;
					visited[i][j] = 1;
					queue<plli> Q;
					Q.push(mp(i,j));
					c = 1;
					while(!Q.empty()){
						plli parent = Q.front();
						Q.pop();
						if(parent.first+1 < a){
							if(visited[parent.first+1][parent.second] != 1 && arr[parent.first+1][parent.second] == 1){
								c++;
								visited[parent.first+1][parent.second] = 1;
								Q.push(mp(parent.first+1,parent.second));
							}
						}
						if(parent.second+1 < b){
							if(visited[parent.first][parent.second+1] != 1 && arr[parent.first][parent.second+1] == 1){
								c++;
								visited[parent.first][parent.second+1] = 1;
								Q.push(mp(parent.first,parent.second+1));
							}
						}
						if(parent.second-1 >= 0){
							if(visited[parent.first][parent.second-1] != 1 && arr[parent.first][parent.second-1] == 1){
								c++;
								visited[parent.first][parent.second-1] = 1;
								Q.push(mp(parent.first,parent.second-1));
							}
						}
						if(parent.first-1 >= 0){
							if(visited[parent.first-1][parent.second] != 1 && arr[parent.first-1][parent.second] == 1){
								c++;
								visited[parent.first-1][parent.second] = 1;
								Q.push(mp(parent.first-1,parent.second));
							}	
						}
						if(parent.first-1 >= 0 && parent.second-1 >= 0){
							if(visited[parent.first-1][parent.second-1] != 1 && arr[parent.first-1][parent.second-1] == 1){
								c++;
								visited[parent.first-1][parent.second-1] = 1;
								Q.push(mp(parent.first-1,parent.second-1));
							}
						}
						if(parent.first-1 >= 0 && parent.second+1 < b){
							if(visited[parent.first-1][parent.second+1] != 1 && arr[parent.first-1][parent.second+1] == 1){
								c++;
								visited[parent.first-1][parent.second+1] = 1;
								Q.push(mp(parent.first-1,parent.second+1));
							}
						}
						if(parent.first+1 < a && parent.second-1 >= 0){
							if(visited[parent.first+1][parent.second-1] != 1 && arr[parent.first+1][parent.second-1] == 1){
								c++;
								visited[parent.first+1][parent.second-1] = 1;
								Q.push(mp(parent.first+1, parent.second-1));
							}
						}
						if(parent.first+1 < a && parent.second+1 < b){
							if(visited[parent.first+1][parent.second+1] != 1 && arr[parent.first+1][parent.second+1] == 1){
								c++;
								visited[parent.first+1][parent.second+1] = 1;
								Q.push(mp(parent.first+1, parent.second+1));
							}
						}
					}
					d = max(c,d);
				}
			}
		}
		cout<<x<<" "<<d<<endl;
	}
	bye;
}

