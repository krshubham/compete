#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,n;
	cin>>t;
	while(t--){
		cin>>n;
		lli arr[n];
		vector<lli> br;
		for (int i = 0; i < n; ++i){
			cin>>arr[i];
		}
		set<lli> s(arr, arr+n);
		for (int i = 0; i < n; ++i){
			lli a;
			cin>>a;
			if(a >= 15)
				br.push_back(a);
		}
		if(s.size() != 1){
			cout<<"No Party"<<endl;
		}
		else{
			if(br.size() == n){
				cout<<"Party"<<endl;
			}
			else{
				cout<<"No Party"<<endl;
			}
		}
	}		
	return 0;
}
