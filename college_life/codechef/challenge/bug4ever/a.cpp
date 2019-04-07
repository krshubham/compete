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
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
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

// int main(){
// 	ios_base::sync_with_stdio(0);
// 	lli t,n,a,b,c,d,e,f,x,y,z,g,h,i;
// 	cin>>t;
// 	char p,q,r,s,u;
// 	while(t--){
// 		cin>>a;//08
// 		cin>>p;//char(:)
// 		cin>>b;//11
// 		cin>>c;//08
// 		cin>>q;//char(:)
// 		cin>>d;//13
// 		cin>>e;//08
// 		cin>>r;//char(:)
// 		cin>>f;
// 		cout<<(c*60+d)-(e*60+f)<<endl;
// 	}
// 	bye;
// }

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,z,g,h,i;
	cin>>t;
	char p,q,r,s,u;
	string st,str,lo,ab,cd,ef;
	while(t--){
		cin>>lo>>st>>str;
		
	}
	bye;
}

