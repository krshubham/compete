#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

bool check(lli x, lli y){
	return y-x;
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,ml,med,k;
	cin>>t;
	while(t--){
		lli n;
		cin >> n;
		vector<lli> a(2 * n), v, ma(2 * n);
		for(int i = 0; i < 2*n; i++) {
			cin>>a[i];
			v.push_back(a[i]);
		}
		sort(v.begin(), v.end());
		ml = (n + 1) / 2;
		med = v[2*n - ml];
		k = 2*n-1;
		for(int i = 0, j = 2*n - 1; i <= j; i++, j--) {
			ma[k] = v[j];
			ma[k-1] = v[i];
			k--;
			k--;
		}
		cout<<med<<endl;
		for(int i = 0; i < 2*n; i++){
			cout<<ma[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
