#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<ulli> vulli;
typedef set<ulli> sulli;
std::set<ulli>::iterator it;
std::pair<std::set<ulli>::iterator,bool> ret;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	ulli n,m,l,r,k;
	cin>>n>>m;
	bool found = 0;
	ulli arr[n];
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}
	while(m--){
		sulli s;
		cin>>l>>r>>k;
		for (int i = 0; i < n; ++i){
			ret = s.insert(arr[i]);
			if(ret.second){
				if(count(arr,arr+n,arr[i]) >= k && (arr[i]>= l) && (arr[i] <= k)){
					cout<<arr[i]<<endl;
					found = 1;
					break;
				}
				found = 0;
			}
			found = 0;
		}
		if(!found){
			cout<<"-1"<<endl;
		}
	}
	return 0;
}
