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

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		cin>>a>>b;
		c = 0;
		vlli v(a);
		for (int i = 0; i < a; ++i){
			cin>>v[i];
			c+=v[i];
		}
		if(c%a != 0){
			cout<<-1<<endl;
			continue;
		}
		lli mean = c/a;
		d = 0;
		vlli vc;
		for (int i = 0; i< a-b; ++i){
			e = b+i;
			if(v[i] < mean){
				x =  mean - v[i];
				d += x;
				v[i] = v[i] + x;
				v[e] = v[e] - x;
			}
			else if(v[i] > mean){
				x = v[i] - mean;
				d += x;
				v[i] = v[i] - x;
				v[e] = v[e] + x;
			}
		}
		bool fl = true;
		for (int i = 0; i < a; ++i){
			if(v[i] != mean){
				cout<<-1<<endl;
				fl = false;
				break;
			}
		}
		if(fl == true){
			cout<<d<<endl;
		}
	}
	bye;
}

