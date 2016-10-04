#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	vector<int> v;
	vector<int>::iterator it;
	while(t--){
		int n;
		cin>>n;
		for (int i = 0; i < n; ++i){
			int a;
			cin>>a;
			v.push_back(a);
		}
		it = min_element(v.begin(),v.end());
		if(*it == v[n-1]){
			cost+= v[n-2];
		}
		else if(*it == v[0]){
			cost+= v[1];
		}
			
	}
	return 0;
}
