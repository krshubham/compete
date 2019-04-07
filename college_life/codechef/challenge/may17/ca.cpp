#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	lli n,k,p,a,r,cs,f=0;
	string s;
	cin>>n>>k>>p;
	std::vector<lli> v;
	for (int i = 0; i < n; ++i){
		cin>>a;
		v.push_back(a);
	}
	cin>>s;
	for (int i = 0; i < p; ++i){
		if(s[i] == '!'){
			rotate(v.rbegin(), v.rbegin() + 1, v.rend());
		}
		else if(s[i] == '?'){
			r = 0;
			for (int i = 0; i < k; ++i){
				r += v[i];
				if(r == k){
					cout<<r<<endl;
					f = 1;
					break;
				}
			}
			if(f == 0){
				cs = r;	
				for (int i = k; i < n; ++i){
					cs += v[i] - v[i-k];
					r = max(r,cs);
					if(r == k){
						cout<<r<<endl;
						f = 1;
						break;
					}
				}
			}
			if(f == 0) cout<<r<<endl;
			f = 0;
		}
	}
	return 0;
}
