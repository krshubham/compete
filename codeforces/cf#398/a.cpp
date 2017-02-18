#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef double dbl;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	lli a;
	cin>>a;
	lli arr[a];
	vector<lli> v;
	for (int i = 0; i < a; ++i){
		cin>>arr[i];
	}
	ll m = *max_element(arr,arr+a);
	for (long long int i = 0; i < a; ++i){
		if(arr[i] == m){
			lli j = arr[i];
			if(std::find(v.begin(), v.end(), j-1) != v.end()) {
				cout<<arr[i]<<" ";
			} 	
			else {
				cout<<arr[i]<<endl;
			}
			while(std::find(v.begin(), v.end(), j-1) != v.end()){
				if(std::find(v.begin(), v.end(), j-2) != v.end()){
					cout<<j-1<<" ";
				}
				else{
					cout<<j-1<<endl;
				}
				j--;
				v.erase(std::remove(v.begin(), v.end(), j), v.end());
			}
			m = j -1;
		}
		else{
			cout<<endl;
			v.push_back(arr[i]);
		}
	}
	return 0;
}
