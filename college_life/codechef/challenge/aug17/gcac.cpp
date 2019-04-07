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
 
typedef struct candidate{
	lli sal;
	string allowed;
} cand;
 
int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<cand> v(n);
		vplli vc(m);
		lli arr[m];
		fill(arr,arr+m,0);
		for (int i = 0; i < n; ++i){
			cin>>v[i].sal;
		}	
		lli max = 0,maxId;
		for (int i = 0; i < m; ++i){
			cin>>a>>b;
			if(a > max){
				max = a;
				maxId = i;
			}
			vc[i] = mp(a,b);
		}
		for (int i = 0; i < n; ++i){
			cin>>v[i].allowed;
		}
		lli selected=0,totalSal=0,unhired = m;
		for (int i = 0; i < n; ++i){
			if(v[i].allowed[maxId] == '1' && vc[maxId].first >= v[i].sal && vc[maxId].second > 0){
				vc[maxId].second--;
				selected++;
				totalSal += vc[maxId].first;
				if(arr[maxId] != 1){
					unhired--;
					arr[maxId] = 1;
				}
				continue;
			}
			for (int j = 0; j < m; ++j){
				if(v[i].allowed[j] == '1' && vc[j].first>=v[i].sal && vc[j].second > 0){
					vc[j].second--;
					selected++;
					totalSal += vc[j].first;
					if(arr[j] != 1){
						unhired--;
						arr[j] = 1;
					}
					break;
				}
			}
		}
		cout<<selected<<" "<<totalSal<<" "<<unhired<<endl;
	}
	bye;
}