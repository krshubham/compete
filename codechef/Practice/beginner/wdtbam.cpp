#include <iostream>
#include <map>
#include <string>
using namespace std;

#define end return 0

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){	
	ios_base::sync_with_stdio(0);
	lli t,n,c,d,max;
	string a,b;
	map<int,lli> m;
	cin>>t;
	while(t--){
		d = 0;
		cin>>n;
		cin>>a>>b;
		for (int i = 0; i < n+1; ++i){
			cin>>c;
			m[i] = c;
		}
		for (int i = 0; i < n; ++i){
			if(a[i] == b[i]) d++;
		}
		if(d == n) cout<<m[n]<<endl;
		else{
			max = 0;
			for (int i = 0; i <=d; ++i){
				if(m[i] > max) max = m[i];
			}
			cout<<max<<endl;
		}
		m.clear();
	}
	end;
}
