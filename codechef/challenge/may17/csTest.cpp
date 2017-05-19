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
	lli n,k,p,a,r,cs,f=0,lv,p1,p2;
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
			lv = v[n-1];
			v.pop_back();
			v.insert(v.begin(),lv);
		}
		else if(s[i] == '?'){
			r = 0;
			for (int i = 0; i < k; ++i){
				r+=v[i];
			}
			cs = r;
			for (int i = k; i < n; ++i){
				if(r == k)
					break;
				cs += v[i] - v[i-k];
				r = max(r,cs);
			}
			cout<<r<<endl;
		}
	}
	return 0;
}
