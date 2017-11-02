#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
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
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	string s;
	char k;
	cin>>s;
	cin>>t;
	while(t--){
		cin>>a>>k;
		lli l = 0;
		lli turn = 0;
		vlli v;
		for(int i = 0; i<n;i++){
			if(s[i] == k && turn == 0){
				turn++;
				x = i;
				continue;
			}
			else if(s[i]==k && turn > 0){
				v.pb(i-x-1);
				x = i;
			}
			else{
				l++;
			}
		}
		lli len = 0;
		lli i = 0;
		while(a != 0){
			if((a-v[i])<0){
				len += a;
				break;
			}
			else{
				a-=v[i];
				len+=(v[i]+2);
				i++;
			}
		}
		if(len == 1){
			len++;
		}
		cout<<len<<endl;
	}
	bye;
}
