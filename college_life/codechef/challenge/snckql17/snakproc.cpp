#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,n,k,m,a,b,d,e;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		k = 0,b=0,a=0,m=0;
		for (int i = 0; i < n; ++i){
			if(s[i] == 'H'){
				if(k == 1){
					cout<<"Invalid"<<endl;
					m = 1;
					a++;
					break;
				}
				else{
					k = 1;
					d = 0;
					a++;
				}
			}
			else if(s[i] == 'T'){
				if(d == 1){
					cout<<"Invalid"<<endl;
					m = 1;
					b++;
					break;
				}
				else{
					d = 1;
					k = 0;	
					b++;
				}
			}
		}
		if(m == 0){
			if(a==b) cout<<"Valid"<<endl;
			else cout<<"Invalid"<<endl;
		}
	}
	return 0;
}
