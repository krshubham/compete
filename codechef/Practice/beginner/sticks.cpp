#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n),a;
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		sort(v.rbegin(),v.rend());
		int max = 1;
		for(int i = 0;i<n;i++){
			if(count(v.begin(),v.end(),v[i])>max){
				a.push_back(v[i]);
			}
		}
		for (int i = 0; i < a.size(); ++i)
		{
			
		}

	}
	return 0;
}
