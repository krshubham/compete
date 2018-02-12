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

lli a,b;
lli arr[1005][1005];

inline bool ok(lli x, lli y){
	return (x >= 0 && y >= 0 && x < a && y < b);
}

inline lli solve(){
	queue<plli> Q;
	rep(i,a){
		rep(j,b){
			if(arr[i][j] == 2){
				Q.push(mp(i,j));
			}
		}
	}
	//delimitter for this case
	Q.push(mp(-1LL,-1LL));
	lli c = 0;
	while(!Q.empty()){
		//while we don't find the delimitter
		bool flag = false;
		while(Q.front().first != -1 && Q.front().second != -1){
			plli point = Q.front();
			//check the right neighbour
			if(ok(point.first+1,point.second) && arr[point.first+1][point.second] == 1){
				if(!flag){
					c++;
					flag = true;
				}
				arr[point.first+1][point.second] = 2;
				point.first++;
				Q.push(point);
				point.first--;
			}
			if(ok(point.first-1,point.second) && arr[point.first-1][point.second] == 1){
				if(!flag){
					c++;
					flag = true;
				}
				arr[point.first-1][point.second] = 2;
				point.first--;
				Q.push(point);
				point.first++;
			}
			if(ok(point.first, point.second+1) && arr[point.first][point.second+1] == 1){
				if(!flag){
					c++;
					flag = true;
				}
				arr[point.first][point.second+1] = 2;
				point.second++;
				Q.push(point);
				point.second--;// remain at the current cell for further conditions
			}
			if(ok(point.first, point.second-1) && arr[point.first][point.second-1] == 1){
				if(!flag){
					c++;
					flag = true;
				}
				arr[point.first][point.second-1] = 2;
				point.second--;
				Q.push(point);
			}
			Q.pop();
		}
		Q.pop(); // the delimitter is popped here;
		if(!Q.empty()){
			Q.push(mp(-1LL,-1LL));
		}
	}
	rep(i,a){
		rep(j,b){
			if(arr[i][j] == 1){
				return -1;
			}
		}
	}
	return c;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t,n,c,d,e,f,x,y;
	cin>>a>>b;
	rep(i,a){
		rep(j,b){
			cin>>arr[i][j];
		}
	}
	(x = solve()) == -1 ? cout<<-1<<endl : cout<<x<<endl;
	bye;
}

