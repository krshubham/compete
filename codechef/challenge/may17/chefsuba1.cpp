#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int solve(vector<lli> arr, lli n, lli k){
	unordered_set<lli> S;
	lli ans = 0;

	for (int i = 0; i < n; i++)
		S.insert(arr[i]);

	for (int i=0; i<n; i++){
		if (S.find(arr[i]-1) == S.end()){
			lli j = arr[i];
			while (S.find(j) != S.end())
				j++;
			ans = max(ans, j - arr[i]);
			if(ans >= k){
				return k;
			}
		}
	}
	return ans;
}


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli n,k,p,a,r=0,cs,f=0;
	string s;
	cin>>n>>k>>p;
	std::vector<lli> v;
	for (int i = 0; i < n; ++i){
		cin>>a;
		if(a == 1){ v.push_back(i);r++;}
	}
	cin>>s;
	// r is the size of the vector containing the indices of the 1's
	for (int i = 0; i < p; ++i){
		if(s[i] == '!'){
			for (int i = 0; i < r; ++i){
				v[i]++;
				if(v[i] == n){
					v[i] = 0;
				}
			}
		}
		else if(s[i] == '?'){
			cout<<solve(v,n,k)<<endl;
		}
	}
	return 0;
}
